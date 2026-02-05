/* 
  <!--
# 410. Split Array Largest Sum

## Problem
Split an array into k contiguous subarrays such that the maximum subarray sum is minimized.

Return that minimized largest sum.

---

## Intuition

We want to minimize the largest subarray sum.

Observation:

Small limit → more splits needed  
Large limit → fewer splits needed  

This monotonic behavior enables Binary Search on answer.

This problem is the same pattern as:
- Allocate Books
- Painter’s Partition

---

## Approach (Binary Search)

1. Search range:
   low = max(nums)
   high = sum(nums)

2. For each mid limit:
   greedily split array without exceeding mid

3. Count subarrays formed.

4. If subarrays ≤ k:
   mid valid → try smaller limit

5. Else:
   increase limit

---

## Greedy Logic

Keep adding elements to current subarray.

If sum exceeds limit:
start new subarray.

---

## Example Insight

nums = [7,2,5,10,8], k = 2

Best split:
[7,2,5] → 14  
[10,8] → 18  

Answer = 18

---

## Complexity

Time: O(n log(sum(nums)))  
Space: O(1)

Key learning:
Binary search on answer + greedy partition.
-->
 */

## Code (C++) 

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());

        int high = 0;
        for (int x : nums)
            high += x;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = 0;
            int parts = 1;

            for (int i = 0; i < nums.size(); i++) {

                if (sum + nums[i] <= mid) {
                    sum += nums[i];
                }
                else {
                    sum = nums[i];
                    parts++;
                }
            }

            if (parts <= k) {
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
