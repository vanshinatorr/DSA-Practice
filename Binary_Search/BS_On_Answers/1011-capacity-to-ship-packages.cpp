/* <!--
# 1011. Capacity To Ship Packages Within D Days

## Problem    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
We must ship packages in order within given days.

Each day the ship can carry weight up to its capacity.

Return the minimum capacity needed to ship all packages within the allowed days.

---

## Intuition
We want the smallest ship capacity that allows shipping within D days.

Observation:

Small capacity → more days required  
Large capacity → fewer days required  

This monotonic behavior allows Binary Search on answer.

---

## Approach (Binary Search)

1. Search range:
   min capacity = max(weights)
   max capacity = sum(weights)

2. For each capacity guess:
   simulate loading packages day by day

3. If required days ≤ given days:
   try smaller capacity

4. Else:
   increase capacity

Repeat until minimum valid capacity is found.

---

## Complexity
Time: O(n log sum(weights))  
Space: O(1)

Key learning:
Binary search on answer + greedy simulation.
--> */

## Code (C++)

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int w : weights)
            high += w;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int load = 0;
            int requiredDays = 1;

            for (int w : weights) {

                if (load + w > mid) {
                    requiredDays++;
                    load = w;
                } 
                else {
                    load += w;
                }
            }

            if (requiredDays <= days) {
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
