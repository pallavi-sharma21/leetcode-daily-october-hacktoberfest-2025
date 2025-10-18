class Solution:
    def findSmallestInteger(self, nums, value):
        ans=0
        temp=[0]*value

        for num in nums:
            x = ((num % value) + value) % value
            temp[x] += 1

        while temp[ans % value] > 0:
            temp[ans % value] -= 1
            ans+=1

        return ans
