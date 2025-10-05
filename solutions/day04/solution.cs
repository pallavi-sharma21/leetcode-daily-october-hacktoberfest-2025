public class Solution
{
    public int MaxArea(int[] height)
    {
        int left = 0;
        int right = height.Length - 1;
        int maxArea = 0;

        while (left < right)
        {
            // Calculate current area
            int h = Math.Min(height[left], height[right]);
            int width = right - left;
            int area = h * width;

            // Update maximum area
            if (area > maxArea)
                maxArea = area;

            // Move the pointer with the smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
}
