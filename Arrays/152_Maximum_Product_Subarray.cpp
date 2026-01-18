/*
====================================================
Problem: 152. Maximum Product Subarray
Platform: LeetCode
Difficulty: Medium
Approach: Prefix & Suffix Product (Optimized)
====================================================

Problem Statement:
Given an integer array nums, find a contiguous subarray
that has the largest product and return the product.

----------------------------------------------------

Key Observation:
- Negative numbers can flip the sign of the product.
- Zero breaks the subarray.
- A maximum product subarray can appear either:
  - from left to right (prefix)
  - or from right to left (suffix)

Hence, we calculate both prefix and suffix products.

----------------------------------------------------

Approach:
1. Maintain two variables:
   - pre  → prefix product (left to right)
   - suf  → suffix product (right to left)
2. If at any point pre or suf becomes 0, reset it to 1
   because subarray must restart after zero.
3. At each index, update the maximum answer using:
   max(pre, suf)

----------------------------------------------------

Algorithm:
1. Initialize:
   - pre = 1, suf = 1
   - ans = INT_MIN
2. Traverse array once:
   - Multiply pre with nums[i]
   - Multiply suf with nums[n - i - 1]
   - Update ans
3. Return ans

----------------------------------------------------

Time Complexity:
- O(n)

Space Complexity:
- O(1)

----------------------------------------------
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int pre = 1, suf = 1;
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (pre == 0) pre = 1;
            if (suf == 0) suf = 1;

            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];

            ans = max(ans, max(pre, suf));
        }

        return ans;
    }
};
