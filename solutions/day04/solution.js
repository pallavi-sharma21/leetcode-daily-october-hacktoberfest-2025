/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let i = 0;
    let j = height.length -1;
    let maxArea = 0;
    while(i<j){
        let minH = height[i] < height[j] ? height[i] : height[j];
        let area = minH * (j - i);
        if(maxArea < area) {
            maxArea = area;
        }
        if(height[i] < height[j]){
            i++;
        } else {
            j--;
        }
    }

    return maxArea;
};
