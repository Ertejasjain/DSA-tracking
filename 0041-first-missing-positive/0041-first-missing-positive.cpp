#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        // Phase 1: Cycle Sort
        // Place each number x in its correct position (index x - 1) if possible
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Phase 2: Find the first mismatch
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions from 1 to n are filled correctly
        return n + 1;
    }
};
