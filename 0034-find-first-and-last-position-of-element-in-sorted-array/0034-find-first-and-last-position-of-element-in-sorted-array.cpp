#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        
        // If the first position is -1, the element doesn't exist in the array.
        // We can skip the second binary search entirely.
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        
        return {first, last};
    }

private:
    int findBound(const std::vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents potential integer overflow
            
            if (nums[mid] == target) {
                bound = mid; // Record the potential answer
                
                if (isFirst) {
                    right = mid - 1; // Keep searching to the left for an earlier occurrence
                } else {
                    left = mid + 1;  // Keep searching to the right for a later occurrence
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return bound;
    }
};
