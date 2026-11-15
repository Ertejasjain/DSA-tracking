#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize a 1D DP array representing the first row (all 1s)
        vector<int> dp(n, 1);

        // Update the array row by row starting from the second row
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] currently holds the value from the cell above (i - 1, j)
                // dp[j - 1] holds the updated value from the cell to the left (i, j - 1)
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
