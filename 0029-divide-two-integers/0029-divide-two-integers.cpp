#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow edge case: -2^31 / -1 = 2^31 (which overflows 32-bit signed int)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        // True if the signs are different, meaning the final answer is negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to prevent overflow during absolute value conversion
        long long dvd = std::labs(dividend);
        long long dvs = std::labs(divisor);
        long long quotient = 0;
        
        // Exponentially subtract the divisor from the dividend
        while (dvd >= dvs) {
            long long tempDivisor = dvs;
            long long multiple = 1;
            
            // Double the divisor using bitwise shift until it exceeds the remaining dividend
            while (dvd >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest doubled divisor found from the dividend
            dvd -= tempDivisor;
            // Add the corresponding multiple to the total quotient
            quotient += multiple;
        }
        
        // Apply the correct sign and cast back to integer
        return isNegative ? -quotient : quotient;
    }
};
