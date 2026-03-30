// ============================================================
// 🔹 Problem: Next Smaller Element (Right Side)
// https://www.naukri.com/code360/problems/next-smaller-element_1112581?utm_source=chatgpt.com&leftPanelTabValue=SUBMISSION
// ============================================================

// 🧩 Problem Statement:
// Given an array, for each element find the next smaller element
// to its right. If none exists, return -1.

// ------------------------------------------------------------
// 💡 Approach: Monotonic Stack (Increasing)
// ------------------------------------------------------------
// - Traverse from right → left
// - Maintain stack such that it is increasing (top is smallest)
// - Pop all elements >= current element
// - If stack empty → answer = -1
// - Else → stack top is answer
// - Push current element

// ------------------------------------------------------------
// ⏱ Complexity:
// Time  : O(n)   (each element pushed & popped once)
// Space : O(n)
// ------------------------------------------------------------

// 🏷 Tags: Stack, Monotonic Stack, Array

// ------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        // Maintain monotonic increasing stack
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Assign answer
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}
