class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use division instead of mid * mid to prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;        // mid is a valid floor candidate
                left = mid + 1;   // try to find a larger valid value
            } else {
                right = mid - 1;  // mid is too large
            }
        }

        return ans;
    }
};
