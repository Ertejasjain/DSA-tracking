#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        // Sort the array to efficiently apply the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        // Initialize with the sum of the first three elements
        long long closestSum = nums[0] + nums[1] + nums[2]; 
        
        // Fix the first element of the triplet
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            // Use two pointers to find the best remaining pair
            while (left < right) {
                long long currentSum = (long long)nums[i] + nums[left] + nums[right];
                
                // If the exact target is found, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // If the current sum is closer to the target, update our closest tracking variable
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on how the current sum compares to the target
                if (currentSum < target) {
                    ++left; // Try a larger sum
                } else {
                    --right; // Try a smaller sum
                }
            }
        }
        
        return closestSum;
    }
};
