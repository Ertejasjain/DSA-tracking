#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is unreachable, we can't reach the end
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest index we can reach from the current position
            maxReach = std::max(maxReach, i + nums[i]);
            
            // Early exit optimization: if we can already reach the last index, return true
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return maxReach >= n - 1;
    }
};
