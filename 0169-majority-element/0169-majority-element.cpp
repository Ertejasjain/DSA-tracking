class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If count falls to 0, pick the current number as the new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // Increment count if it matches candidate, decrement otherwise
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};