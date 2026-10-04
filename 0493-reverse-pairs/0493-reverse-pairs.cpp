#include <vector>

class Solution {
private:
    int mergeAndCount(std::vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        // 1. Count important reverse pairs
        for (int i = low; i <= mid; i++) {
            // Use 2LL to cast to long long to prevent integer overflow
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // 2. Standard merge step to keep the array sorted
        std::vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // Copy back the sorted elements into the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count pairs in the left half, right half, and split pairs
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += mergeAndCount(nums, low, mid, high);

        return count;
    }

public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};