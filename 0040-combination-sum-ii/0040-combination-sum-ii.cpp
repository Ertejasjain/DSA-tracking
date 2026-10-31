#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, int target, std::vector<int>& current_comb, 
                   std::vector<int>& candidates, std::vector<std::vector<int>>& result) {
        // Base case: If we successfully hit the target sum
        if (target == 0) {
            result.push_back(current_comb);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Early Pruning: If the current number exceeds the remaining target,
            // no subsequent numbers can satisfy it because the array is sorted.
            if (candidates[i] > target) {
                break;
            }

            // Duplicate Handling: Skip identical elements at the same recursion depth
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Make a choice
            current_comb.push_back(candidates[i]);

            // Recurse to the next element (i + 1 ensures each element is used only once)
            backtrack(i + 1, target - candidates[i], current_comb, candidates, result);

            // Undo the choice (Backtrack)
            current_comb.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_comb;

        // Sorting is crucial for duplicate skipping and early pruning
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, current_comb, candidates, result);
        return result;
    }
};
