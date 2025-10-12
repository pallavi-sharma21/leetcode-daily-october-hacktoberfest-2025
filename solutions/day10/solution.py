# Day 10 - LeetCode Problem: Taking Maximum Energy From the Mystic Dungeon
# Contributed by @Meghana-2124

from typing import List

class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        dp = [None] * n

        def dfs(i):
            if i >= n:
                return 0
            if dp[i] is not None:
                return dp[i]
            dp[i] = energy[i] + dfs(i + k)
            return dp[i]

        max_energy = float('-inf')
        for i in range(n):
            max_energy = max(max_energy, dfs(i))
        return max_energy
