package solutions.day09;

class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length, m = mana.length;
        
        // done[i] = the earliest time when wizard i is ready for the next potion
        long[] done = new long[n + 1];

        // Process each potion sequentially
        for (int j = 0; j < m; j++) {

            // Step 1: Compute brewing time for each wizard on this potion
            for (int i = 0; i < n; i++) {
                // Wizard i starts only when both:
                // 1) previous wizard finishes the current potion
                // 2) wizard i finishes the previous potion
                done[i + 1] = Math.max(done[i + 1], done[i]) + (long) skill[i] * mana[j];
            }

            // Step 2: Backward adjustment for synchronization
            for (int i = n - 1; i > 0; i--) {
                done[i] = done[i + 1] - (long) skill[i] * mana[j];
            }
        }

        // Final result: when the last wizard finishes the last potion
        return done[n];
    }
}
