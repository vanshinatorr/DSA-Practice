/*
Merge Intervals

Problem:
You are given a list of intervals where each interval is represented as
[start, end]. Merge all overlapping intervals and return the result.

Approach 
1. Sort all intervals based on starting time.
2. Take the first interval and add it to the answer list.
3. For every next interval:
   - If its start is less than or equal to the end of the last interval in answer,
     then the intervals overlap → merge them.
   - Otherwise, add the interval as it is.
4. Return the merged intervals.

Why it works:
- Sorting ensures intervals are processed in order.
- Comparing only with the last merged interval is enough.

Time Complexity:
- O(n log n) → due to sorting

Space Complexity:
- O(n) → for storing merged intervals

Platforms:
- LeetCode (Merge Intervals) que.56

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        int n = intervals.size();

        // Edge case: no intervals
        if (n == 0) return ans;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Add first interval
        ans.push_back(intervals[0]);

        // Step 3: Merge remaining intervals
        for (int i = 1; i < n; i++) {

            // If current interval overlaps with last merged interval
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            // If no overlap
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
