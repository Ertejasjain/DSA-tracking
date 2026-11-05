class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result) {
        // Base case: If we have reached the end of the array, a valid permutation is formed
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);       // Do: Swap the current element into position
            backtrack(nums, index + 1, result); // Recurse: Fill the remaining slots
            swap(nums[index], nums[i]);       // Undo: Backtrack to restore the original state
        }
    }
};
