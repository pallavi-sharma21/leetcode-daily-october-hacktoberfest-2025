// Day 18: Maximum number of distinct elements after performing +/- k operations
import java.util.*;

public class MaxDistinctElements {

    public int maxDistinct(int[] numbers, int k) {
        Arrays.sort(numbers); 
        Set<Integer> uniqueNumbers = new HashSet<>(); 

        for (int number : numbers) {
            if (!uniqueNumbers.contains(number)) {
                uniqueNumbers.add(number);  // Already unique, add it
            } else {
                boolean adjusted = false;
                for (int diff = 1; diff <= k; diff++) {
                    int lower = number - diff;
                    int higher = number + diff;
                    
                    if (!uniqueNumbers.contains(lower)) {
                        uniqueNumbers.add(lower);
                        adjusted = true;
                        break;
                    } else if (!uniqueNumbers.contains(higher)) {
                        uniqueNumbers.add(higher);
                        adjusted = true;
                        break;
                    }
                }
                if (!adjusted) continue;  // Cannot adjust, skip
            }
        }

        return uniqueNumbers.size(); 
    }
}

   
