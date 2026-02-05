/* <!--
# Aggressive Cows

## Problem
Given stall positions and k cows, place cows such that the minimum distance between any two cows is maximized.

Return that maximum possible minimum distance.

---

## Intuition

We want to maximize the minimum distance.

Observation:

Small distance → cows always placeable  
Large distance → placement may fail  

This monotonic behavior allows Binary Search on answer.

---

## Approach (Binary Search)

1. Sort stall positions.
2. Search distance range:
   min = 0
   max = last - first stall

3. For each mid distance:
   greedily place cows
   count how many can be placed

4. If cows ≥ k:
   mid possible → try bigger distance

5. Else:
   reduce distance

---

## Greedy Placement Logic

Place first cow at first stall.

For each stall:
if distance from last placed cow ≥ mid  
→ place next cow

---

## Dry Run (Example)

stalls = [1,2,4,8,9], k = 3

Binary search tries distances:

mid=4 → fail  
mid=1 → works  
mid=2 → works  
mid=3 → works  

Largest valid distance = 3

---

## Complexity

Time: O(n log(maxDistance))  
Space: O(1)

Key learning:
Binary search on answer + greedy placement.
-->
*/


## Code (C++)

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int cows = 1;
        int last_pos = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last_pos >= mid) {
                cows++;
                last_pos = stalls[i];
            }
        }

        if (cows >= k) {
            ans = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return ans;
}
```
