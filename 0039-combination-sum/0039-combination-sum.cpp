#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        
        // Sorting allows for early pruning of the search space
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int startIndex, 
                   std::vector<int>& currentCombination, std::vector<std::vector<int>>& result) {
        // Base case: if target is met, record the successful combination
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            // Pruning: Since candidates are sorted, if the current element exceeds 
            // the remaining target, no subsequent elements will fit either.
            if (candidates[i] > target) {
                break; 
            }

            // 1. Choose: Add the current candidate to our pathway
            currentCombination.push_back(candidates[i]);

            // 2. Explore: Recurse with the reduced target.
            // Note: We pass 'i' as the new startIndex instead of 'i + 1' 
            // because the problem allows reusing the same number multiple times.
            backtrack(candidates, target - candidates[i], i, currentCombination, result);

            // 3. Un-choose: Backtrack by removing the element before trying the next loop iteration
            currentCombination.pop_back();
        }
    }
};
