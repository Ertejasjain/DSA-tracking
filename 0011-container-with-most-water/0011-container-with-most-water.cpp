#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate width and limiting height
            int width = right - left;
            int current_height = std::min(height[left], height[right]);
            
            // Update the maximum water found so far
            int current_water = current_height * width;
            max_water = std::max(max_water, current_water);
            
            // Move the pointer that points to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};
