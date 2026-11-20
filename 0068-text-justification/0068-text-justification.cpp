#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();

            // 1. Greedily pack as many words as possible into the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            int totalChars = 0;
            for (int k = i; k < j; ++k) {
                totalChars += words[k].length();
            }

            int totalSpaces = maxWidth - totalChars;
            string line = "";

            // 2. Handle Left-Justification (Last line or single-word line)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Pad remaining spaces on the right
                line += string(maxWidth - line.length(), ' ');
            } 
            // 3. Handle Full-Justification (Multiple words, not the last line)
            else {
                int gaps = numWords - 1;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        // Leftmost 'extraSpaces' gaps get 1 additional space
                        int spacesToApply = spacesPerGap + (k - i < extraSpaces ? 1 : 0);
                        line += string(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the next line's starting word
        }

        return result;
    }
};
