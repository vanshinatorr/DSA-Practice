 /* <!--
# 1283. Find the Smallest Divisor Given a Threshold 
on Leetcode problem 1283 : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

## Problem
Given an array `nums` and an integer `threshold`, choose a positive divisor and divide all elements by it.  
Each division result is rounded up (ceil).

Return the smallest divisor such that the total sum is ≤ threshold.

---

## Intuition
We want the smallest divisor that keeps the sum within a limit.

Observation:
Smaller divisor → larger sum  
Larger divisor → smaller sum  

This monotonic behavior allows Binary Search.

---

## Approach (Binary Search)

1. Search range = [1 → max(nums)]
2. For each divisor:
   ceil(a/b) = (a + b - 1) / b
3. If sum ≤ threshold → try smaller divisor
4. Otherwise → increase divisor

---

## Complexity
Time: O(n log max(nums))  
Space: O(1)

Key learning:
Binary search on answer + ceiling division trick.
-->

## Code (C++)*/

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long sum = 0;

            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```
