class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1);
        long long current_val = 1;
        
        for (int k = 1; k < rowIndex; ++k) {
            // Calculate C(rowIndex, k) using the previous element
            current_val = current_val * (rowIndex - k + 1) / k;
            row[k] = static_cast<int>(current_val);
        }
        
        return row;
    }
};