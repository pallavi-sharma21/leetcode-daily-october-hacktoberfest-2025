🌧️ Avoid Flood in the City - Java Solution

This repository contains a Java implementation of the avoidFlood algorithm, which solves the "Avoid Flood in The City" problem, commonly found in coding interviews and online judges such as LeetCode.

🧩 Problem Statement

You're given an array rains of length n, where:

rains[i] > 0 means it rains over lake rains[i] on day i.

rains[i] == 0 means it's a dry day, and you can choose to dry any one lake.

You must avoid any lake flooding. A lake floods if it rains over it when it's already full and hasn't been dried.

Your goal is to return an array result such that:

If it rains on day i, result[i] == -1.

If it’s a dry day on day i, result[i] is the lake number you choose to dry that day.

If it's not possible to avoid a flood, return an empty array.

✅ Example
int[] rains = {1,2,0,0,2,1};
int[] result = new Solution().avoidFlood(rains);
// Output: [-1,-1,2,1,-1,-1]


Explanation:

Day 0: Rain on lake 1 → fill lake 1

Day 1: Rain on lake 2 → fill lake 2

Day 2: Dry day → dry lake 2

Day 3: Dry day → dry lake 1

Day 4: Rain on lake 2 → OK (was dried on day 2)

Day 5: Rain on lake 1 → OK (was dried on day 3)

🔍 Approach

This solution uses:

A Map<Integer, Integer> (lakeFull) to track which lakes are currently full and when they were last filled.

A TreeSet<Integer> (dryDays) to store indices of dry days. TreeSet allows efficient lookup for the next available dry day after a lake was last filled.

An int[] result array to store the output as per the rules.

Key Steps:

Iterate over each day:

If it’s raining on a lake:

Check if that lake is already full (i.e., in lakeFull).

If it is, use TreeSet.higher() to find the next dry day after the last rain on that lake.

If no such dry day exists → return new int[0] (a flood is unavoidable).

Else, assign that dry day to dry the lake, and remove it from the set.

Update the last day it rained on this lake.

If it’s a dry day:

Add the index to dryDays, and temporarily set result[i] = 1 (can be changed later).

💡 Time and Space Complexity

Time Complexity: O(n log n)

TreeSet operations (add, remove, higher) take O(log n)

Space Complexity: O(n)

For lakeFull, dryDays, and result