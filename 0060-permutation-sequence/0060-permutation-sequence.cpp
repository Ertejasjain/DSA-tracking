#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // Calculate (n - 1)! and populate available digits [1, 2, ..., n]
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string ans = "";
        k = k - 1; // Convert k to 0-based indexing
        
        while (true) {
            // Find the index of the current digit
            int index = k / fact;
            ans += to_string(numbers[index]);
            
            // Remove the used digit
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            // Update k and factorial for the remaining digits
            k %= fact;
            fact /= numbers.size();
        }
        
        return ans;
    }
};
