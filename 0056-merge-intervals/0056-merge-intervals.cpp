#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // 2. Iterate through the sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the last merged interval
            if (intervals[i][0] <= merged.back()[1]) {
                // Merge by updating the end time to the maximum of both
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap, so add the current interval to the result
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
