#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int sLen = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalWindowLen = wordCount * wordLen;

        // Step 1: Build the frequency map of the required words
        unordered_map<string, int> targetCounts;
        for (const string& word : words) {
            targetCounts[word]++;
        }

        // Step 2: Run a sliding window for each possible starting offset
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> currentCounts;
            int matchedWords = 0;

            // Slide the right boundary of the window by wordLen chunks
            while (right + wordLen <= sLen) {
                // Pull out the word at the right boundary
                string word = s.substr(right, wordLen);
                right += wordLen;

                // Case A: The word is part of our target list
                if (targetCounts.count(word)) {
                    currentCounts[word]++;
                    matchedWords++;

                    // If we have more copies of this word than needed, 
                    // shrink the window from the left until it becomes valid
                    while (currentCounts[word] > targetCounts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCounts[leftWord]--;
                        matchedWords--;
                        left += wordLen;
                    }

                    // If the number of correctly matched words matches our target list, 
                    // a valid substring is found
                    if (matchedWords == wordCount) {
                        result.push_back(left);
                    }
                } 
                // Case B: The word is completely invalid
                else {
                    // Reset the window entirely and move left to the right position
                    currentCounts.clear();
                    matchedWords = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
