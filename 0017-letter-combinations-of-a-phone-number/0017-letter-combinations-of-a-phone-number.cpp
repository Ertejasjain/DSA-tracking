#include <vector>
#include <string>

class Solution {
private:
    // Mapping of phone digits from 0 to 9 to their corresponding letters
    const std::vector<std::string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& currentCombination, std::vector<std::string>& result) {
        // Base case: if the current combination matches the length of digits, save it
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        // Get the letters corresponding to the current digit
        std::string letters = digitToLetters[digits[index] - '0'];
        
        // Loop through all letters mapped to the current digit
        for (char letter : letters) {
            currentCombination.push_back(letter);       // Choose the letter
            backtrack(digits, index + 1, currentCombination, result); // Recurse to the next digit
            currentCombination.pop_back();        // Backtrack (remove the letter)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Edge case: if the input string is empty, return an empty vector
        if (digits.empty()) {
            return result;
        }
        
        std::string currentCombination = "";
        backtrack(digits, 0, currentCombination, result);
        
        return result;
    }
};
