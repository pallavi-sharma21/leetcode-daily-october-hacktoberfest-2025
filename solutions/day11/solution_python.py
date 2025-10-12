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
        return l  # first valid index for nums[i] + 3

    def maximumTotalDamage(self, power: List[int]) -> int:
        count = Counter(power)
        nums = sorted(count.keys())
        n = len(nums)

        t = [0] * (n + 1)  # dp array
        result = float('-inf')

        # Iterate backward
        for i in range(n - 1, -1, -1):
            # Option 1: skip current
            skip = t[i + 1] if i + 1 < n else 0

            # Find next valid index where damage ≥ nums[i] + 3
            j = self.search(nums, i + 1, n - 1, nums[i] + 3)

            # Option 2: take current
            take = nums[i] * count[nums[i]]
            if j < n:
                take += t[j]

            # Store best result for this index
            t[i] = max(skip, take)
            result = max(result, t[i])

        return result
