class Solution {
    minTime(skill, mana) {
        // Example input:
        // skill = [1, 5, 2, 4]
        // mana  = [5, 1, 4, 2]

        const n = skill.length; // number of wizards (4)
        const m = mana.length;  // number of potions (4)

        // 'done' array keeps track of the total time each wizard
        // has taken so far to brew all processed potions.
        const done = new Array(n + 1).fill(0);

        // Outer loop → iterate through each potion
        for (let j = 0; j < m; j++) {

            // Inner loop (forward): calculate when each wizard finishes
            // brewing potion j based on their skill and previous timings.
            for (let i = 0; i < n; i++) {
                // done[i + 1] = max(done[i + 1], done[i]) + mana[j] * skill[i]
                // ensures synchronization — next wizard starts after
                // both current wizard & current potion are ready.
                done[i + 1] = Math.max(done[i + 1], done[i]) + mana[j] * skill[i];
            }

            // Second inner loop (backward): adjusts intermediate values
            // to maintain proper dependency for the next potion.
            // This ensures that when we move to the next potion,
            // all wizards start with consistent state.
            for (let i = n - 1; i > 0; i--) {
                done[i] = done[i + 1] - mana[j] * skill[i];
            }
        }

        // The final wizard’s completion time after the last potion
        // gives the total minimum time required.
        return done[n];
    }
}

// Example usage:
const skill = [1, 5, 2, 4];
const mana = [5, 1, 4, 2];

const solution = new Solution();
const result = solution.minTime(skill, mana);
console.log(result); // Expected Output: 110
