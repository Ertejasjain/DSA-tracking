#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Optimization: Reserve capacity to avoid overhead and rehashing
        std::unordered_set<int> numSet;
        numSet.reserve(nums.size()); 
        numSet.insert(nums.begin(), nums.end());
        
        int longestStreak = 0;
        
        for (int num : numSet) {
            // Only start counting if it is the absolute beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count the length of the current sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
