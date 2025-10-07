public class Solution {
    public int[] avoidFlood(int[] rains) {
        Map<Integer, Integer> lakeFull = new HashMap<>(); // lake -> day it's full
        TreeSet<Integer> dryDays = new TreeSet<>(); // stores indices of dry days
        int n = rains.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.add(i);
                result[i] = 1; // default value, will be changed if used to dry a lake
            } else {
                result[i] = -1; // raining, can't dry
                if (lakeFull.containsKey(lake)) {
                    int lastRainDay = lakeFull.get(lake);
                    Integer dryDay = dryDays.higher(lastRainDay);
                    if (dryDay == null) {
                        return new int[0]; // flood, no dry day available
                    }
                    result[dryDay] = lake; // dry this lake on that dry day
                    dryDays.remove(dryDay);
                }
                lakeFull.put(lake, i); // update last rain day
            }
        }

        return result;
    }
}
