from typing import List

"""
LeetCode Problem 3494: Find the Minimum Amount of Time to Brew Potions

Problem:
You are given two integer arrays, `skill` and `mana`, each of length `n`. The `i`-th element of `skill` represents the skill level required to brew the `i`-th potion, and the `i`-th element of `mana` represents the mana cost to brew the `i`-th potion.

You can brew a potion if your current skill level is greater than or equal to the required skill level for that potion. Initially, your skill level is 0, and your mana is unlimited.

Each time you brew a potion, your skill level increases by the skill level of the potion you brewed. The time taken to brew a potion is equal to the mana cost of that potion.

Return the minimum total time required to brew all the potions.
"""

def min_time_to_brew_potions(skill: List[int], mana: List[int]) -> int:
    # Combine skill and mana into a list of tuples
    potions = list(zip(skill, mana))
    
    # Sort potions by skill level
    potions.sort()
    
    # Initialize variables
    total_time = 0
    current_skill = 0
    
    # Simulate brewing each potion
    for potion_skill, potion_mana in potions:
        if current_skill < potion_skill:
            # Increase skill to match potion's requirement
            total_time += potion_skill - current_skill
            current_skill = potion_skill
        # Add the mana cost of brewing this potion
        total_time += potion_mana
        # After brewing, increase skill
        current_skill += potion_skill
    
    return total_time


# Example usage
if __name__ == "__main__":
    skill = [2, 3, 1]
    mana = [5, 6, 4]
    result = min_time_to_brew_potions(skill, mana)
    print(result)  # Expected Output: 15