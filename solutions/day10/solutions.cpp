class Solution {
public:
int solve(vector<int>& energy,int i,int k,int n,vector<int> &dp){
      if(i>=n){
        return 0;
      }
      if(dp[i]!=-1){
        return dp[i];
      }
     return dp[i]=energy[i]+solve(energy,i+k,k,n,dp);
      
}
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int> dp(n+1,-1);
        for(int i=0;i<n;i++){
           ans=max(solve(energy,i,k,n,dp),ans);
        }
          return ans;
    }
};