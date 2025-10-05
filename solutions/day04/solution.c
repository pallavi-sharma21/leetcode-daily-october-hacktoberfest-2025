int maxArea(int *height, int heightSize)
{
    int i = 0;
    int j = heightSize - 1;
    int res = 0;

    // Start from both ends and move towards the center to find the maximum area
    while (i < j)
    {
        int minH = height[i] < height[j] ? height[i] : height[j];
        int area = (j - i) * minH;
        if (area > res)
            res = area;

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return res;
}
