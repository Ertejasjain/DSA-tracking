#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        // Base case: the 1st term of the sequence is always "1"
        std::string current = "1";
        
        // Generate the sequence up to the nth term
        while (--n > 0) {
            std::string next_seq = "";
            int len = current.length();
            
            for (int i = 0; i < len; ) {
                int count = 1;
                // Count consecutive identical characters
                while (i + 1 < len && current[i] == current[i + 1]) {
                    count++;
                    i++;
                }
                
                // Append the frequency and the character itself
                next_seq += std::to_string(count) + current[i];
                i++; // Move to the next distinct group
            }
            // Transition to the newly generated string
            current = std::move(next_seq);
        }
        
        return current;
    }
};
