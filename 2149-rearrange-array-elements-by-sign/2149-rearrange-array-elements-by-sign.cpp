class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        
        int posIdx = 0; // Pointer for positive numbers (even indices)
        int negIdx = 1; // Pointer for negative numbers (odd indices)
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIdx] = nums[i];
                posIdx += 2; // Move to the next even index
            } else {
                ans[negIdx] = nums[i];
                negIdx += 2; // Move to the next odd index
            }
        }
        
        return ans;
    }
};