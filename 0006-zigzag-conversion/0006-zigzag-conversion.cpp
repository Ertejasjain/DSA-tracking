#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: if only one row or string is too short, no zigzag pattern is possible
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Initialize a vector of strings to track characters in each row
        std::vector<std::string> rows(std::min(numRows, static_cast<int>(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        // Traverse each character in the string
        for (char c : s) {
            rows[currentRow] += c;
            
            // Reverse direction if we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down based on the current direction
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all row strings to form the final result
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};
