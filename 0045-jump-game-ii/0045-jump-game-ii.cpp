#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_jump_end = 0;
        int farthest_reachable = 0;
        
        // We don't need to process the last element because once we 
        // reach or cross it, we are already at the destination.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the maximum distance we can reach from the current window
            farthest_reachable = std::max(farthest_reachable, i + nums[i]);
            
            // If we have reached the end of the current jump's range
            if (i == current_jump_end) {
                jumps++;
                current_jump_end = farthest_reachable;
                
                // Optimization: If we can already reach the last index, stop early
                if (current_jump_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};
