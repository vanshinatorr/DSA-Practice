/* <!--
# 1539. Kth Missing Positive Number

## Problem
Given a sorted increasing array of positive integers, return the k-th missing positive number.

---

## Intuition
If the array had no missing numbers:

index 0 → value 1  
index 1 → value 2  
...

So expected value = index + 1

Missing count at index i:

missing = arr[i] - (i + 1)

We binary search to find the first index where missing ≥ k.

---

## Approach (Binary Search)

1. Compute missing numbers using:
   missing = arr[mid] - (mid + 1)

2. If missing < k:
   search right side

3. Else:
   search left side

After search:

answer = k + low

Why?
low tells how many real numbers are present before kth missing.

---

## Complexity
Time: O(log n)  
Space: O(1)

Key learning:
Binary search on derived monotonic property.
--> */

## Code (C++)

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};
```
