/*
Problem: 3494. Find the Minimum Amount of Time to Brew Potions
Language: Go
Description:
You are given two integer arrays, skill and mana, of lengths n and m respectively.
In a lab, n wizards must brew m potions in order. Each potion has a mana capacity mana[j]
and must pass through all wizards sequentially.

The time taken by the ith wizard on the jth potion is:
    time_ij = skill[i] * mana[j]

We must return the minimum total time required for brewing all potions properly.

Approach:
- Maintain an array `done[]` representing the earliest time each wizard can start the next potion.
- For each potion, process all wizards in order:
  * Wizard i starts after both:
      (1) previous wizard finishes the current potion
      (2) wizard i finishes the previous potion
  * Update done[i+1] accordingly.
- Then propagate backward to synchronize start times for the next potion.
- After all potions, done[n] gives the total minimum brew time.

Time Complexity: O(n * m)
Space Complexity: O(n)
*/

package main

import (
	"fmt"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func minTime(skill []int, mana []int) int64 {
	n := len(skill)
	m := len(mana)
	done := make([]int64, n+1)

	for j := 0; j < m; j++ {
		// Step 1: Each wizard brews potion j in order
		for i := 0; i < n; i++ {
			val := int64(skill[i]) * int64(mana[j])
			if done[i] > done[i+1] {
				done[i+1] = done[i]
			}
			done[i+1] += val
		}

		// Step 2: Synchronize backward for next potion
