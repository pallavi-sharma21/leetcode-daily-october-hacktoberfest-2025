class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results=[]
        subset=[]
        def sub(i):
            if i>len(nums):
                return
            if i==len(nums):
                result.append(subset.copy())
                return
            subset.append(nums[i])
            sub(i+1)
            subset.pop()
            sub(i+1)
        sub(0)
        return results
        
            
        