/*
------------------------------------------------------------
🧠 Problem: Next Greater Element II (Circular Array)
https://leetcode.com/problems/next-greater-element-ii/
------------------------------------------------------------

Given a circular array nums, return the next greater element
for every element.

The next greater element of x is the first greater element
to its right (circularly). If it doesn't exist, return -1.

------------------------------------------------------------
💡 Approach (Monotonic Stack + Circular Traversal)

1. Traverse array from right → left (2*n times)
2. Use modulo (i % n) to simulate circular behavior
3. Maintain a monotonic decreasing stack
4. Pop all smaller or equal elements (useless)
5. Stack top = next greater element
6. Only fill answer when i < n (real indices)

------------------------------------------------------------
⏱️ Time Complexity:
O(n)
- Each element pushed & popped at most once

📦 Space Complexity:
O(n)
- Stack + answer array

------------------------------------------------------------
🔥 Key Concepts:
- Monotonic Stack
- Circular Array (using modulo)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);   // initialize with -1

        // Traverse 2*n times for circular effect
        for (int i = 2*n - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Fill answer only in first pass
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            // Push current element
            st.push(nums[i % n]);
        }

        return ans;
    }
};
