#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // Find the first occurrence of needle in haystack
        size_t found = haystack.find(needle);
        
        // If found, return the index; otherwise, return -1
        if (found != std::string::npos) {
            return found;
        }
        return -1;
    }
};
