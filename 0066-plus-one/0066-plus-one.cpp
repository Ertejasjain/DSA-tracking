#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the digits from right to left (least to most significant)
        for (int i = n - 1; i >= 0; --i) {
            // If the current digit is less than 9, simply increment and return
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            // Otherwise, the digit was 9, so it becomes 0 and the carry continues
            digits[i] = 0;
        }
        
        // If the loop completes, all digits were 9 (e.g., 999 -> 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
