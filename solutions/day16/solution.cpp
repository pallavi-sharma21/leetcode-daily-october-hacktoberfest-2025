#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = 0;

        vector<int> a(value, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            int x = ((nums[i] % value) + value) % value;
			a[x]++;
            
        }

    
        while(a[ans % value]--){
            ans++;
        } 
	
        

        return ans;
    }
};