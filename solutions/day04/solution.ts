function maxArea(height: number[]): number {
  let i = 0;
  let j = height.length - 1;
  let res = 0;

  // Start from both ends and move towards the center to find the maximum area
  while (i < j) {
    res = Math.max(res, (j - i) * Math.min(height[i], height[j]));
    if (height[i] < height[j]) i++;
    else j--;
  }

  return res;
}
