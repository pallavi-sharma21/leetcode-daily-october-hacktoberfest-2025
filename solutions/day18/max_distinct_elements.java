import java.util.*;

public class MaxDistinctElements {
  
    public int maxDistinct(int[] numbers, int k) {
        if (numbers.length == 0) return 0;

        Arrays.sort(numbers); 
        int count = 0;
        int prev = Integer.MIN_VALUE >> 1; 

        for (int i = 0; i < numbers.length; i++) {
            int a = numbers[i];
            int low = a - k;
            int high = a + k;
            int x = prev + 1;

            if (x < low) x = low;     
            if (x <= high) {        
                count++;
                prev = x;            
            }
        }

        return count;  
    }
}
