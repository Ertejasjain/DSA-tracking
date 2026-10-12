#include <string>
#include <vector>

class Solution {
public:
    int romanToInt(std::string s) {
        int total = 0;
        // Use a lookup array sized 128 for direct ASCII character index mapping
        std::vector<int> roman(128);
        
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        for (int i = 0; i + 1 < s.length(); ++i) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]]; // Subtractive property
            } else {
                total += roman[s[i]]; // Additive property
            }
        }
        
        // Add the last character's value explicitly
        return total + roman[s.back()];
    }
};
