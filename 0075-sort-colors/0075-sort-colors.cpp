class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                  // Boundary for 0s (Red)
        int mid = 0;                  // Current element scanner
        int high = nums.size() - 1;   // Boundary for 2s (Blue)

        while (mid <= high) {
            if (nums[mid] == 0) {
                // If the element is 0, swap it to the lower boundary
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If the element is 1, it's already in the correct middle zone
                mid++;
            } 
            else { // nums[mid] == 2
                // If the element is 2, swap it to the higher boundary
                std::swap(nums[high], nums[mid]);
                high--;
                // Note: Do not increment 'mid' here because the swapped 
                // element from 'high' hasn't been evaluated yet.
            }
        }
    }
};