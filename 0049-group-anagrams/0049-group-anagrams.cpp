#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Map to group original strings by their sorted canonical keys
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (const std::string& str : strs) {
            std::string key = str;
            // Sorting the string creates a unique signature for all its anagrams
            std::sort(key.begin(), key.end());
            
            // Push the original word into its corresponding anagram group
            anagramMap[key].push_back(str);
        }
        
        // Collect all grouped vectors from the hashmap to form the result
        std::vector<std::vector<std::string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};
