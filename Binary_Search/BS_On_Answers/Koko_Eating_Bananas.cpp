/* # Koko Eating Bananas (Binary Search on Answer)

Que 875
https://leetcode.com/problems/koko-eating-bananas/ 

## Problem Statement
Koko loves to eat bananas. There are `n` piles of bananas where  
`piles[i]` represents the number of bananas in the i-th pile.

Koko eats bananas at a speed of `k` bananas per hour.
Each hour, she can eat bananas from only one pile.
If a pile has less than `k` bananas, she eats all of them in that hour.

Given `h` hours, return the **minimum integer `k`** such that Koko can eat all the bananas within `h` hours.

---

## Example
Input:
piles = [3, 6, 7, 11], h = 8

Output:
4

Explanation:
At speed k = 4, total hours needed = 8.

---

## Approach (Binary Search on Answer)

- Minimum possible speed = 1
- Maximum possible speed = max element in piles
- If speed increases, total time required decreases (monotonic)
- Hence, apply Binary Search on the answer space

Steps:
1. low = 1, high = max(piles)
2. For mid speed, calculate total hours using ceil division
3. If hours <= h, store answer and try smaller speed
4. Else, increase speed



Complexity Analysis
Time Complexity: O(n log M)
Space Complexity: O(1)

Where:
n = number of piles
M = maximum bananas in a pile
--- */

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int bananas : piles) {
                // ceil(bananas / mid)
                hours += (bananas + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;        // valid speed
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need larger speed
            }
        }

        return ans;
    }
};
