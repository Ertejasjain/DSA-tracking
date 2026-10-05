class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Handle empty array edge case
        if (nums.empty()) return 0;

        // Initialize tracking variables with the first element
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        // Traverse the array starting from the second element
        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // If the current number is negative, swapping max and min 
            // accounts for the sign-flip when multiplied by a negative number.
            if (num < 0) {
                std::swap(currMax, currMin);
            }

            // The new currMax/currMin can be either the standalone element 
            // or the extended product from the previous subarray step.
            currMax = std::max(num, currMax * num);
            currMin = std::min(num, currMin * num);

            // Update the global maximum product found so far
            maxProd = std::max(maxProd, currMax);
        }

        return maxProd;
    }
};