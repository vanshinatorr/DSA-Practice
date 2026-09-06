https://leetcode.com/problems/sqrtx/?utm_source=chatgpt.com

find square root

class Solution {
public:
    int mySqrt(int x) {
        
        long long low = 1;
        long long high = x;
        int ans = -1;

        if (x == 0) {
            return 0;
        }

        if (x == 1) {
            return 1;
        }

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
