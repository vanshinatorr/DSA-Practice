/*
-------------------------------------------------------
🔹 Problem: Rotate Array by D Positions (Left Rotation)
-------------------------------------------------------

Given an array `arr` of size `n`, rotate the array to the left by `d` positions.

Example:
Input:  arr = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]

-------------------------------------------------------
🔹 Approach: Reversal Algorithm
-------------------------------------------------------

Steps:
1. Normalize d → d = d % n
2. Reverse first d elements
3. Reverse remaining (n - d) elements
4. Reverse whole array

Why it works:
- First reversal:   [2,1,3,4,5]
- Second reversal:  [2,1,5,4,3]
- Final reversal:   [3,4,5,1,2] ✅

-------------------------------------------------------
🔹 Time Complexity: O(n)
🔹 Space Complexity: O(1) (In-place)

-------------------------------------------------------
🔹 Edge Cases:
- d = 0 → no change
- d > n → handled by modulus
- n = 1 → no effect

-------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();

        // Handle edge case
        if (n == 0) return;

        // Normalize d
        d = d % n;

        // Step 1: Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Step 2: Reverse remaining elements
        reverse(arr.begin() + d, arr.end());

        // Step 3: Reverse entire array
        reverse(arr.begin(), arr.end());
    }
};


/*
-------------------------------------------------------
🔹 Common Mistakes:
-------------------------------------------------------

❌ Forgetting d = d % n
   → Causes wrong output when d > n

❌ Wrong reverse ranges
   → Off-by-one errors (very common)

❌ Mixing left rotation with right rotation logic

-------------------------------------------------------
🔹 Dry Run (Quick):
-------------------------------------------------------

arr = [1,2,3,4,5], d = 2

Step 1 → [2,1,3,4,5]
Step 2 → [2,1,5,4,3]
Step 3 → [3,4,5,1,2]

-------------------------------------------------------
*/
