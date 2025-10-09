## 🧠 LeetCode October Daily Challenge – Day 08

### 🏷️ Problem: 3494. Find the Minimum Amount of Time to Brew Potions

You are given two integer arrays `skill` and `mana`, both of length `n`.

- Each potion `i` requires a minimum skill level `skill[i]` to brew.
- Brewing potion `i` costs `mana[i]` time (mana).
- Initially, your skill is `0`.  
- When you brew potion `i`, you spend `mana[i]` time and your skill increases by `skill[i]`.

You must brew all potions in some order.  
Return the **minimum total time** needed to brew all of them.

---

### 💡 Approach:

1. Combine `skill` and `mana` pairs and **sort them by skill requirement**.
2. Start with skill = 0 and total time = 0.
3. For each potion in order:
   - Brew the potion only when your skill meets the requirement.
   - Add `mana[i]` to total time.
   - Increase your skill by `skill[i]`.

Sorting ensures that we always brew the easiest (lowest skill) potions first, minimizing the waiting time for harder potions.

---

### 🔧 Solution Details:
- **Language Used:** Python  
- **Time Complexity:** O(n log n) (due to sorting)  
- **Space Complexity:** O(n) (for storing potion pairs)  

---

### 🌟 Additional Notes:
- Handles all edge cases, including:
  - Unordered input skill levels  
  - Potions with zero mana or skill  
- Sorting + simulation is optimal and avoids unnecessary reprocessing.
