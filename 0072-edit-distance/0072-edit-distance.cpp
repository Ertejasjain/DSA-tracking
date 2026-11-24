#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases: converting an empty string to a non-empty string (or vice versa)
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // Delete all characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // Insert all characters into word1
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match; no new operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Take the minimum of the three operations + 1
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};
