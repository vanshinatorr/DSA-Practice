/*
------------------------------------------------------------
🧠 Problem: Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/
------------------------------------------------------------

Given two arrays nums1 and nums2 where nums1 is a subset of nums2.

For each element in nums1, find the next greater element in nums2.
The next greater element is the first greater element to the right.
If none exists, return -1.

------------------------------------------------------------
💡 Approach (Monotonic Stack + HashMap)

1. Traverse nums2 from right → left
2. Use a stack to maintain decreasing order
3. Pop all smaller or equal elements (they are useless)
4. The top of stack = next greater element
5. Store result in unordered_map
6. Traverse nums1 and fetch answers from map

------------------------------------------------------------
⏱️ Time Complexity:
O(n + m)
- n = size of nums2
- m = size of nums1

📦 Space Complexity:
O(n)
- Stack + HashMap

------------------------------------------------------------
🔥 Key Concept:
Monotonic Decreasing Stack
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;                  // stack for processing
        unordered_map<int,int> nge;     // map: element → next greater

        int n = nums2.size();

        // Step 1: process nums2
        for (int i = n - 1; i >= 0; i--) {
            
            // remove useless elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // store next greater
            if (st.empty()) {
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = st.top();
            }

            // push current element
            st.push(nums2[i]);
        }

        // Step 2: build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};
