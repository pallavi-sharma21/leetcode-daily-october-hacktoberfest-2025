class Solution {
public int numWaterBottles(int numBottles, int numExchange) {

   //drinkedBottles store the total number of bottles you can drink
   int drinkedBottles=0;

   //emptyBottles store the number of empty bottles you currently have
   int emptyBottles=0;

    while(numBottles!=0)
    {
        // Drink all the current full bottles you have
        drinkedBottles+=numBottles;

        // All the bottles you drank now become empty bottles
        emptyBottles+=numBottles;

        // Exchange empty bottles for new full bottles
        numBottles=emptyBottles/numExchange;

        // Update the number of empty bottles left after exchange
        emptyBottles=emptyBottles%numExchange;
        
    }

     // Return the total number of bottles you were able to drink
    return drinkedBottles;

        
    }
}