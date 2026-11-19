#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop from the end of both strings until all digits and carry are processed
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // Append the remainder (0 or 1) to the result string
            result += to_string(sum % 2);
            
            // Update carry for the next column
            carry = sum / 2;
        }

        // Digits were added in reverse order, so reverse the final string
        reverse(result.begin(), result.end());
        
        return result;
    }
};
