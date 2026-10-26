#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // 1. If the target is found, return its index immediately
            if (nums[mid] == target) {
                return mid;
            }

            // 2. Identify if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the boundaries of the sorted left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Narrow search space to the left half
                } else {
                    low = mid + 1;  // Narrow search space to the right half
                }
            } 
            // 3. Otherwise, the right half must be sorted
            else {
                // Check if target lies within the boundaries of the sorted right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Narrow search space to the right half
                } else {
                    high = mid - 1; // Narrow search space to the left half
                }
            }
        }

        // Target not found in the array
        return -1;
    }
};
