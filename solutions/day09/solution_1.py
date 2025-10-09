from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        # example: skill = [1,5,2,4], mana = [5,1,4,2]
        
        n = len(skill) # get len of skill list (4)
        m = len(mana) # get len of mana list (4)
        
        # define the prefix placeholder with size of n
        prefix = [0] * n

        # fill the prefix[i] with sum of prev element and skill[i]
        for i in range(1, n): 
            prefix[i] = prefix[i - 1] + skill[i] # on this example [0, 5, 7, 11]
            # 0 + 5 = 5
            # 5 + 2 = 7
            # 7 + 4 = 11

        # define the time required for wizard 0 to complete potion 0
        total_time = skill[0] * mana[0] # 1 * 5 = 5

        for j in range(1, m):
            # get max time needed for wizard 0 complete the potion j
            max_time = skill[0] * mana[j] # 1 * 5 = 5
            for i in range(1, n):
                # get time difference from wizard 0 complete potion j - 1 and wizard 0 complete potion j
                # 5 * 5 - 0 * 1 = 25
                diff_time = prefix[i] * mana[j-1] - prefix[i-1] * mana[j] 
                # if diff_time is greater than max_time then replace the value
                if diff_time > max_time: 
                    max_time = diff_time # replace 5 to 25
            # add max time to total time
            total_time += max_time # 5 + 25 = 30
        
        return total_time + prefix[-1] * mana[-1] # compute total time with last value of prefix and mana

if __name__ == "__main__":
    skill = [1,5,2,4]
    mana = [5,1,4,2]

    solution = Solution()
    mintime = solution.minTime(skill, mana)
    print(mintime) # 110