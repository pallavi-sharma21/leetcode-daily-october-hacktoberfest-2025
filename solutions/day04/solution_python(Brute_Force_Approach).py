"""
                Container With Most Water (LeetCode 11)

Problem Statement: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Brute Force Approach:
- Iterate over all possible pairs of lines (i, j) where i < j.
- For each pair, calculate the water area: (j - i) * min(height[i], height[j])
- Keep track of the maximum area found.

Complexity Analysis:
Time Complexity: O(n^2)
where n = number of vertical lines, i.e., the length of the input array height
Space Complexity: O(1)

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        max_area = 0
        
        for i in range(n):
            for j in range(i + 1, n):
                width = j - i
                area = width * min(height[i], height[j])
                max_area = max(max_area, area)
        
        return max_area


"""
class Solution(object):
Defines a class Solution.

On LeetCode, you are required to implement your solution as a method inside this class.

    def maxArea(self, height):
        #:type height: List[int]
        #:rtype: int

Defines a method maxArea that takes height as input.
height is a list of integers representing the heights of vertical lines.
:rtype: int means the function will return an integer — the maximum area of water.

        n = len(height)
Stores the number of vertical lines.

        max_area = 0
max_area stores the maximum water area found so far.
Initially set to 0 because we haven’t calculated any areas yet.

        for i in range(n):
            for j in range(i + 1, n):
Loop through every possible pair of lines (i, j), where i < j.

                width = j - i
Calculates the width of the container formed by lines i and j.

                area = width * min(height[i], height[j])
Calculates the area of water the current pair can hold.

                max_area = max(max_area, area)
Updates max_area if the current area is bigger than the previous maximum.

        return max_area
Returns the maximum area found after checking all pairs.
"""


