/* <!--
# Minimize Max Distance to Gas Station

## Problem
Given sorted gas station positions and k new stations:

Insert k stations such that the maximum distance between adjacent stations is minimized.

Stations can be placed at fractional positions.

Return minimum possible maximum distance.

---

## Intuition

We want the smallest distance D such that we can ensure
all adjacent gaps ≤ D.

Observation:

Small D → need more stations  
Large D → fewer stations  

Monotonic behavior → Binary Search on answer (continuous).

---

## Approach (Binary Search on Double)

1. Search range:
   low ≈ 0
   high = max existing gap

2. For each candidate distance mid:

   For each gap:
   required stations = ceil(gap / mid) - 1

3. Sum required stations.

4. If required ≤ k:
   mid possible → try smaller

5. Else:
   increase distance

Stop when precision reached.

---

## Precision Handling

We stop when:

high - low ≤ 1e-6

This ensures accurate floating answer.

---

## Complexity

Time: O(n log(range / precision))  
Space: O(1)

Key learning:
Binary search on continuous values + greedy gap splitting.
-->
*/
## Code (C++)

```cpp
double minimiseMaxDistance(vector<int> &arr, int k) {

    int n = arr.size();

    double low = 1e-6;
    double high = 0.0;

    for (int i = 1; i < n; i++) {
        high = max(high, (double)(arr[i] - arr[i - 1]));
    }

    while (high - low > 1e-6) {

        double mid = low + (high - low) / 2.0;
        int needed = 0;

        for (int i = 1; i < n; i++) {
            double gap = arr[i] - arr[i - 1];
            needed += ceil(gap / mid) - 1;
        }

        if (needed <= k) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return high;
}
```
