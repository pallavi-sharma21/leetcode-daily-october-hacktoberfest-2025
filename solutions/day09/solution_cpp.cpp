class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        
        // done[i] = the earliest time when wizard i is ready for the next potion
        vector<long long> done(n + 1, 0);

        // Process each potion in order
        for (int j = 0; j < m; ++j) {

            // Step 1: Each wizard brews the current potion in order
            for (int i = 0; i < n; ++i) {
                // Wizard i starts only when both:
                // 1) previous wizard finishes the current potion
                // 2) wizard i finishes the previous potion
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * skill[i] * mana[j];
            }

            // Step 2: Adjust the done array backward
            // to synchronize wizard start times for next potion
            for (int i = n - 1; i > 0; --i) {
                done[i] = done[i + 1] - 1LL * skill[i] * mana[j];
            }
        }

        // The last wizard's completion time after all potions = total minimum time
        return done[n];
    }
};
