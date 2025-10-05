class Solution {
public:
    int numWaterBottles(int b, int ex) {
        int ans=0;
         int rem=0;
        while((b+rem)>=ex){
           ans+=b;
           rem+=b;
           b=0;
           int changables=rem/ex;
           b=changables;
           rem=rem%ex;
        }
        ans+=b;
        return ans;
    }
};
