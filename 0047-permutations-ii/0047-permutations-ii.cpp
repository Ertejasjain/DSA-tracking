#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_path;
        std::vector<bool> used(nums.size(), false);
        
        // 1. Sort to bring duplicates next to each other
        std::sort(nums.begin(), nums.end());
        
        // 2. Start the backtracking process
        backtrack(nums, used, current_path, result);
        
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& used, 
                   std::vector<int>& current_path, std::vector<std::vector<int>>& result) {
        // Base Case: If the path length equals input size, we found a valid permutation
        if (current_path.size() == nums.size()) {
            result.push_back(current_path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (used[i]) continue;
            
            // Pruning Condition: Skip duplicates
            // If the current number is the same as the previous one, and the previous 
            // number wasn't used yet in this recursive branch, skip it to avoid duplicates.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            
            // Make choice
            used[i] = true;
            current_path.push_back(nums[i]);
            
            // Recurse
            backtrack(nums, used, current_path, result);
            
            // Undo choice (Backtrack)
            current_path.pop_back();
            used[i] = false;
        }
    }
};
