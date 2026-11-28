#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // Write pointer for the valid portion of the array
        
        for (int num : nums) {
            // Keep the first two elements automatically, or any element 
            // that is different from the element two positions back
            if (k < 2 || num != nums[k - 2]) {
                nums[k] = num;
                k++;
            }
        }
        
        return k;
    }
};
