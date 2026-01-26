/*     482. Minimum Number of Days to Make m Bouquets
       https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1897717545/

🧠 Problem Summary
You are given an array bloomDay where bloomDay[i] is the day the i-th flower blooms.
You want to make m bouquets, each requiring k adjacent flowers.
Return the minimum number of days required to make m bouquets.
If it is not possible, return -1.


Approach 

The minimum possible day = min(bloomDay)
The maximum possible day = max(bloomDay)
Apply binary search on days
For a given day:
Count how many bouquets can be formed using adjacent bloomed flowers
If bouquets >= m → feasible → try smaller day
Else → need more days


⏱️ Complexity
Time Complexity: O(n log(maxDay))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Impossible case
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquets = 0;
            int cnt = 0;

            // Count bouquets possible on 'mid' day
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    cnt++;
                    if (cnt == k) {
                        bouquets++;
                        cnt = 0;
                    }
                } else {
                    cnt = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                high = mid - 1;  // try earlier day
            } else {
                low = mid + 1;   // need more days
            }
        }
        return ans;
    }
};
