#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Pointer to track the position of valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not the target value
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move it to the front
                k++;               // Move the write pointer forward
            }
        }
        
        return k; // Return the count of elements not equal to val
    }
};
