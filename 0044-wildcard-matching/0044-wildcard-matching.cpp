#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, matchIdx = -1;

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Pattern has '*', record the checkpoint
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++; // Greedily try matching 0 characters first
            }
            // Case 3: Mismatch occurred, but we have a previous '*' checkpoint to backtrack to
            else if (starIdx != -1) {
                pIdx = starIdx + 1; // Reset pattern pointer to after the '*'
                matchIdx++;         // Advance the string match pointer (let '*' consume 1 more char)
                sIdx = matchIdx;    // Reset string pointer to retry
            }
            // Case 4: Mismatch and no '*' to fall back on
            else {
                return false;
            }
        }

        // Check if remaining characters in pattern are all '*'
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};
