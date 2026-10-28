#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Tracker arrays: rows, columns, and 3x3 boxes
        // Size 9x9 tracks digits 1-9 (indices 0-8) across 9 structures
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }

                // Map '1'-'9' to index 0-8
                int num = board[r][c] - '1'; 
                
                // Map the row and column index to a unique 3x3 sub-box index (0 to 8)
                int box_index = (r / 3) * 3 + (c / 3);

                // If the number has already been seen in this row, col, or box, it's invalid
                if (rows[r][num] || cols[c][num] || boxes[box_index][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_index][num] = true;
            }
        }

        return true;
    }
};
