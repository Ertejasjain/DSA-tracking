#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& ans,
                   vector<bool>& cols, vector<bool>& diag, vector<bool>& antiDiag) {
        // Base Case: If we successfully placed queens in all rows, save the solution
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            // Check if placing a queen at (r, c) is safe
            if (cols[c] || diag[r - c + n] || antiDiag[r + c]) {
                continue; 
            }

            // Place the queen and flag the column/diagonals
            board[r][c] = 'Q';
            cols[c] = diag[r - c + n] = antiDiag[r + c] = true;

            // Recurse into the next row
            backtrack(r + 1, n, board, ans, cols, diag, antiDiag);

            // Backtrack: Remove the queen and unflag the column/diagonals
            board[r][c] = '.';
            cols[c] = diag[r - c + n] = antiDiag[r + c] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        // Optimization arrays to replace nested checking loops
        vector<bool> cols(n, false);
        vector<bool> diag(2 * n, false);
        vector<bool> antiDiag(2 * n, false);

        backtrack(0, n, board, ans, cols, diag, antiDiag);
        return ans;
    }
};
