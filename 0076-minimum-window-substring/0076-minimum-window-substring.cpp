#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // ASCII frequency map for characters required from t
        vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int required = t.length(); // Total characters still needed
        int left = 0;
        int minLen = INT_MAX;
        int bestLeft = -1;

        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); right++) {
            // If s[right] is still needed, decrement the required counter
            if (count[s[right]] > 0) {
                required--;
            }
            // Decrement frequency (characters not in t become negative)
            count[s[right]]--;

            // Once all characters from t are covered, shrink from the left
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    bestLeft = left;
                }

                // Restore frequency as left pointer moves forward
                count[s[left]]++;
                
                // If frequency becomes > 0, we lost a necessary character
                if (count[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return bestLeft == -1 ? "" : s.substr(bestLeft, minLen);
    }
};
