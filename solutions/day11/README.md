## [3186. Maximum Total Damage With Spell Casting](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/)

A magician has various spells.
You are given an array `power`, where each element represents the damage of a spell. Multiple spells can have the same damage value.
It is a known fact that if a magician decides to cast a spell with a damage of `power[i]`, they **cannot** cast any spell with a damage of `power[i] - 2`, `power[i] - 1`, `power[i] + 1`, or `power[i] + 2`.
Each spell can be cast **only once**.
Return the **maximum** possible _total damage_ that a magician can cast.

## Intuition

This problem asks us to find the **maximum possible total damage** we can achieve by selecting spells, subject to a specific constraint: if a spell with damage $X$ is cast, then spells with damage $X-2, X-1, X+1$, and $X+2$ are forbidden.

The detailed intuition to solve this problem relies on deducing the necessity of Dynamic Programming (DP) combined with specific preprocessing steps:
### 1. Failure of the Greedy Approach
Our initial instinct might be to employ a greedy strategy: always choose the spell with the largest damage value currently available.

- **Why it fails:** Choosing the largest value might forbid multiple other high-value spells, leading to a suboptimal result. For instance, in the set ${7, 6, 6, 1}$, taking 7 results in a total of 8 damage (7 + 1), but taking the two 6s first (which forbids 7) yields $6+6+1 = 13$.
- **Conclusion:** Since a greedy choice doesn't guarantee the optimal global solution, we must explore all possibilities: whether to **Take** a spell or **Skip** it. This take/skip decision structure immediately suggests a solution using **Recursion**, which, due to overlapping subproblems, will be optimized using **Memoization (DP)**.
### 2. Preprocessing for Efficiency
A naive recursive approach faces two major challenges: repeatedly traversing the array to check which elements are forbidden, and constantly tracking the forbidden values. To make the recursion efficient, we apply two key preprocessing steps:
#### A. Sorting the Damage Values
Since the order in which we cast the spells does not affect the final total damage, we can process them in any order.

- **Benefit:** Sorting the unique damage values (e.g., in ascending order) allows us to easily find the next available spell after making a choice, as forbidden elements ($X+1, X+2$) will lie directly to the right. This removes the need to constantly re-traverse the entire array to find a safe element.

#### B. Handling Duplicates with a Frequency Map
A critical observation is that if we select a spell with damage $X$, other spells that also have damage $X$ are **not** forbidden (since $X$ itself is outside the forbidden range $X-2, X-1, X+1, X+2$).

- **Solution:** We use a **Map** to store the frequency (count) of each unique damage value.
- **Simplification:** We create a new array (`nums`) containing only the **unique** damage values, sorted in ascending order. If we decide to take a value $\text{nums}[i]$, the total damage collected from that choice is $\text{nums}[i] \times \text{Frequency}[\text{nums}[i]]$.

### 3. The DP Transition (Take or Skip)
Now we define a DP state, $T[i]$, as the maximum total damage we can achieve starting from the unique damage value at index $i$ in our sorted `nums` array. At each index $i$, we have two options:

#### Option 1: Skip (Not Taking $\text{nums}[i]$)
If we choose to skip the damage value $\text{nums}[i]$, there are no consequences for future indices. We simply move to the next unique damage value and calculate the maximum damage from there.

$$\text{Skip} = T[i+1]$$

#### Option 2: Take (Taking $\text{nums}[i]$)

If we choose to take the damage value $\text{nums}[i]$:
1. **Calculate Current Damage:** We gain the total damage from all instances of this spell: $\text{nums}[i] \times \text{Map}[\text{nums}[i]]$.
2. **Determine the Jump:** We must find the next safe index $j$ to continue the recursion/DP. Since taking $\text{nums}[i]$ forbids values up to $\text{nums}[i] + 2$, the next safe element must have a value greater than or equal to $\text{nums}[i] + 3$.
3. **Find Next Index ($j$):** Because the `nums` array is sorted, we can use an efficient search method like **Lower Bound** (or binary search) to quickly find the first index $j$ corresponding to a value $\geq \text{nums}[i] + 3$.
4. **Recurse/Jump:** We add the result from the safe starting point $j$.

$$\text{Take} = (\text{nums}[i] \times \text{Map}[\text{nums}[i]]) + T[j]$$

#### Final Recurrence:

$$T[i] = \max(\text{Skip}, \text{Take})$$

### 4. Resolving the Past Constraint (The Guarantee)
A final piece of intuition addresses the constraint on the negative side: if we take $X$ (at index $i$), how do we know we didn't previously take $X-1$ or $X-2$, which would have forbidden $X$?

- **The Guarantee:** If we are currently considering index $i$ (value $X$), it is implicitly guaranteed that no element taken in the past would have forbidden $X$.
- **Explanation:** If we had taken an element $Y$ previously such that $Y+1=X$ or $Y+2=X$, our earlier "Take" decision would have used the Lower Bound search to **jump over** $X$ and move to an index $j > i$. Since we reached index $i$, it must be a valid, un-forbidden choice. Therefore, we only need to worry about the future elements we forbid ($\text{nums}[i]+1$ and $\text{nums}[i]+2$), which is handled by the jump calculation.

### 5. Final Structure (Bottom-Up DP)
Since the calculation of $T[i]$ depends on results from indices $i+1$ and $j$ (where $j > i$), we must solve the subproblems first. In the bottom-up DP implementation, this means we must iterate the index $i$ from **Right to Left** (from $n-1$ down to 0).

The resulting solution has a time complexity of $\mathbf{O(N \log N)}$, where $N$ is the count of unique elements, due to the $O(N)$ loop combined with the $O(\log N)$ Lower Bound search inside the loop.

## Approach

- **Step 1:** Group spells by damage and count them.
- **Step 2:** Process the unique damage values in sorted order.
- **Step 3:** For each damage value, decide:  
    ◦ **Take it:** Add its total value to the best result from a compatible previous spell.  
    ◦ **Skip it:** Carry forward the previous best result.
- **Step 4:** The answer is the max of these two choices at each step.

## Example 
`power = [1, 1, 3, 4]`

|Step|Damage|Count|Total Value|Compatible Next ≥ (damage + 3)|take (value + t[j])|skip|t[i] = max(take, skip)|
|---|---|---|---|---|---|---|---|
|i=2|4|1|4|—|4|0|4|
|i=1|3|1|3|j=3 (no next)|3|4|4|
|i=0|1|2|2|j=1 (3≥4? No → skip to j=2)|2 + t[2] = 6|4|6|
**Answer = 6**
Which matches casting damages **1, 1, 4**.

## Code Implementation for Dynamic Programming & Binary Search Approach

```python
from collections import Counter
from typing import List

class Solution:
    def search(self, nums: List[int], l: int, r: int, target: int) -> int:
        # Custom binary search: find the first index where nums[mid] >= target
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return l

    def maximumTotalDamage(self, power: List[int]) -> int:
        count = Counter(power)
        nums = sorted(count.keys())
        n = len(nums)

        t = [0] * (n + 1)
        result = float('-inf')

        # Iterate backward
        for i in range(n - 1, -1, -1):
            skip = t[i + 1] if i + 1 < n else 0
            j = self.search(nums, i + 1, n - 1, nums[i] + 3)

            take = nums[i] * count[nums[i]]
            if j < n:
                take += t[j]
            t[i] = max(skip, take)
            result = max(result, t[i])
            
        return result
```

## Complexity Analysis
| Type      | Complexity                             |
| --------- | -------------------------------------- |
| **Time**  | `O(n log n)` - sorting + binary search |
| **Space** | `O(n)` -  DP table and frequency map   |
|           |                                        |

## ## Key Insight

This problem is a **House Robber variant** where adjacency is defined not by indices,  
but by **damage proximity (±2)**.  
We maximize total “damage” by skipping conflicting values and combining compatible ones.