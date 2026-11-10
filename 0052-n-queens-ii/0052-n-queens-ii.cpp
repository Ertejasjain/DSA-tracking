#include <vector>

class Solution {
private:
    int total_solutions = 0;

    void backtrack(int row, int n, std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        // Base case: If we successfully placed a queen in every row, increment solution count
        if (row == n) {
            total_solutions++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1_idx = row + col;
            int d2_idx = row - col + n - 1;

            // Check if placing a queen here is safe
            if (cols[col] || diag1[d1_idx] || diag2[d2_idx]) {
                continue; 
            }

            // Action: Place the queen and mark constraints
            cols[col] = diag1[d1_idx] = diag2[d2_idx] = true;

            // Recurse: Move to the next row
            backtrack(row + 1, n, cols, diag1, diag2);

            // Undo: Backtrack and reset constraints for other paths
            cols[col] = diag1[d1_idx] = diag2[d2_idx] = false;
        }
    }

public:
    int totalNQueens(int n) {
        total_solutions = 0;
        
        // Lookup arrays initialized to false
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n - 1, false);
        std::vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, cols, diag1, diag2);
        return total_solutions;
    }
};
