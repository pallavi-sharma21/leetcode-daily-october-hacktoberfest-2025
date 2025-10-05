class Solution {
    public int maxArea(int[] height) {
       int area=0;
       int left=0,right=height.length-1;
       int maxi=0;
       while(left<right){
            area=Math.min(height[left],height[right])*(right-left);
            maxi=Math.max(maxi,area);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
       }
       return maxi;
    }
}

