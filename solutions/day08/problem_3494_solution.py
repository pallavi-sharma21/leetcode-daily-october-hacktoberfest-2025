from typing import List

def min_time_to_brew_potions(skill: List[int], mana: List[int]) -> int:
    potions = list(zip(skill, mana))
    potions.sort()
    
    total_time = 0
    current_skill = 0
    
    for potion_skill, potion_mana in potions:
        if current_skill < potion_skill:
            total_time += potion_skill - current_skill
            current_skill = potion_skill
        total_time += potion_mana
        current_skill += potion_skill
    
    return total_time

if __name__ == "__main__":
    skill = [2, 3, 1]
    mana = [5, 6, 4]
    result = min_time_to_brew_potions(skill, mana)
    print(result)
