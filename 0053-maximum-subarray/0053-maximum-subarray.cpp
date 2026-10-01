class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x = INT_MIN;
        int z =0;
        for(int i =0; i<nums.size(); i++){
            z = max(nums[i],z+nums[i]);
            x = max(z,x);
        }
        return x;
    }
};