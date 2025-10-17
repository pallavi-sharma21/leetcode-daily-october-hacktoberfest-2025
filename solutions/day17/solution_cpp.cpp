#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int n;
    int K;
    // memo key: i, mask, usedChange (0 or 1) → best number of partitions from i onward
    unordered_map<long long,int> memo;
    
    int maxPartitionsAfterOperations(string _s, int k) {
        s = _s;
        n = s.size();
        K = k;
        memo.clear();
        // We compute partitions *after* index 0; we add 1 for the first partition
        return dfs(0, 0, 0) + 1;
    }
    
    // i = current index in s
    // mask = bitmask of letters seen in current partition
    // used = 0 if we have not used our “change” yet, 1 if we already used it
    int dfs(int i, int mask, int used) {
        if (i >= n) {
            return 0;  // no more characters, no more partitions
        }
        long long key = ((long long)i << 32) | ((long long)mask << 1) | used;
        if (memo.count(key)) return memo[key];
        
        int res = 0;
        
        // Option 1: don’t change s[i], use its original letter
        {
            int bit = 1 << (s[i] - 'a');
            int newMask = mask | bit;
            if (__builtin_popcount(newMask) > K) {
                // we must start a new partition here
                res = max(res, 1 + dfs(i+1, bit, used));
            } else {
                // continue the same partition
                res = max(res, dfs(i+1, newMask, used));
            }
        }
        
        // Option 2: change s[i] to some other letter (if not used yet)
        if (used == 0) {
            for (int c = 0; c < 26; ++c) {
                int bit = 1 << c;
                int newMask = mask | bit;
                if (__builtin_popcount(newMask) > K) {
                    // would exceed, so we must start a new partition
                    res = max(res, 1 + dfs(i+1, bit, 1));
                } else {
                    // can continue same partition after change
                    res = max(res, dfs(i+1, newMask, 1));
                }
            }
        }
        
        memo[key] = res;
        return res;
    }
};
