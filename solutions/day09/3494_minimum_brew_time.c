/*
Problem: 3494. Find the Minimum Amount of Time to Brew Potions
Language: C
Description:
You are given two integer arrays, skill and mana, of lengths n and m respectively.
In a lab, n wizards must brew m potions in order. Each potion has a mana capacity mana[j] and must pass through all the wizards sequentially.
The time taken by the ith wizard on the jth potion is time_ij = skill[i] * mana[j].
We must return the minimum total time required for brewing all potions properly.

Approach:
- Maintain an array `done[]` representing the earliest time each wizard can start the next potion.
- For every potion (j), process each wizard (i):
  * Wizard i starts after both:
      (1) the previous wizard finishes the current potion
      (2) this
