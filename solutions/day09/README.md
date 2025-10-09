🧪 *3494. Find the Minimum Amount of Time to Brew Potions* — now with **Approach**, **Intuition**, and **Dry Run** sections added 👇

---

# 🧪 3494. Find the Minimum Amount of Time to Brew Potions

## 🧭 Problem Description

You are given two integer arrays:

* `skill[i]` — the brewing speed factor of the *i-th wizard*
* `mana[j]` — the mana capacity of the *j-th potion*

There are `n` wizards and `m` potions.

Each potion must go **through all wizards sequentially**
(wizard 0 → wizard 1 → … → wizard n−1) to be brewed correctly.

The **time taken** by wizard `i` on potion `j` is:

```
time[i][j] = skill[i] * mana[j]
```

Once a wizard finishes brewing a potion, it is **immediately** passed to the next wizard.
However, a wizard **cannot start a new potion** until they have finished the previous one.

You need to determine the **minimum total time** required for all `m` potions to be brewed properly.

---

## 🧩 Example

### Example 1

```
Input:
skill = [1, 5, 2, 4]
mana  = [5, 1, 4, 2]

Output:
110
```

| Potion | Wizard 0 done | Wizard 1 done | Wizard 2 done | Wizard 3 done |
| :----- | :------------ | :------------ | :------------ | :------------ |
| 0      | 5             | 30            | 40            | 60            |
| 1      | 52            | 53            | 58            | 64            |
| 2      | 54            | 58            | 78            | 102           |
| 3      | 86            | 88            | 98            | 110           |

```
done = [0, 6, 35, 42, 64]
```

…and similarly for the next potions until we get:

✅ **Final done = [0, 86, 88, 98, 110]**

So, **Answer = 110**

---

## 💡 Intuition

Think of this as a **production line**:

* Each wizard is a **station**.
* Each potion must pass through all wizards one by one.
* A wizard can’t start the next potion until:

  * The previous potion is done at that station, **and**
  * The potion has arrived from the previous wizard.

Hence, the process must be **synchronized** between wizards —
similar to how jobs flow in an assembly line.

The key idea is to track the **finish time** for each wizard after each potion.

---

## 🧩 Approach

1. **Use a `done` array** of size `n + 1`

   * `done[i]` represents the time when the `i-th` wizard finishes their work.
   * Initially, all are `0`.

2. **Iterate through each potion `j` (0 → m−1):**

   * For each wizard `i` (0 → n−1):

     * The wizard can start the potion only when both:

       * The potion has arrived from the previous wizard (`done[i]`), and
       * The wizard has finished their previous potion (`done[i+1]`).
     * So we take the maximum of both times.

   ```
   done[i + 1] = max(done[i + 1], done[i]) + skill[i] * mana[j]
   ```

3. **Adjust backflow:**

   * After computing, we re-adjust `done[i]` backward so it reflects the potion’s movement synchronously.

   ```
   done[i] = done[i + 1] - skill[i] * mana[j]
   ```

4. After all potions are processed,
   the total minimum brewing time is `done[n]`.

---

## 🧮 Dry Run

Let’s dry-run for the given example:

```
skill = [1, 5, 2, 4]
mana  = [5, 1, 4, 2]
```

### Step 1: Initialize

```
done = [0, 0, 0, 0, 0]
```

### Step 2: Potion 0 (mana = 5)

```
Wizard 0: done[1] = max(0, 0) + 1*5 = 5
Wizard 1: done[2] = max(0, 5) + 5*5 = 30
Wizard 2: done[3] = max(0, 30) + 2*5 = 40
Wizard 3: done[4] = max(0, 40) + 4*5 = 60
done = [0, 5, 30, 40, 60]
```

### Step 3: Potion 1 (mana = 1)

```
Wizard 0: done[1] = max(5, 0) + 1*1 = 6
Wizard 1: done[2] = max(30, 6) + 5*1 = 35
Wizard 2: done[3] = max(40, 35) + 2*1 = 42
Wizard 3: done[4] = max(60, 42) + 4*1 = 64
done = [0, 6, 35, 42, 64]
```

### Step 4: Continue similarly for potions 2 & 3

After all updates, we get:

```
done = [0, 86, 88, 98, 110]
```

✅ Final Answer = **110**

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> done(n + 1, 0);

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * skill[i] * mana[j];
            }
            for (int i = n - 1; i > 0; --i) {
                done[i] = done[i + 1] - 1LL * skill[i] * mana[j];
            }
        }

        return done[n];
    }
};
```

---

## ⏰ Time Complexity

* Outer loop → over all potions (`m`)
* Inner loops → over all wizards (`n`)

```
Time Complexity: O(n × m)
```

---

## 💾 Space Complexity

```
Space Complexity: O(n)
```

(only one `done` vector of size `n + 1`)

---

## 🧠 Key Takeaways

* This is a **flow synchronization** or **assembly line scheduling** type of problem.
* Maintain `done` array to track the cumulative finish times per wizard.
* The formula

  ```
  done[i + 1] = max(done[i + 1], done[i]) + skill[i] * mana[j]
  ```

  captures the real-time dependency between consecutive wizards and potions.
* Careful handling of overlapping potion processes ensures minimum total brewing time.

---
