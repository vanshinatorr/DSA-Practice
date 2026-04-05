// File: sliding_window_minimum.cpp

/*
----------------------------------------
🔹 Problem: Sliding Window Minimum
----------------------------------------

Given an array nums and window size k,
return minimum of each sliding window.

Example:
nums = [1,3,-1,-3,5], k = 3
Output = [-1, -3, -3]

----------------------------------------
⚠️ Note:
----------------------------------------

- This problem is NOT directly available on LeetCode.
- It is an additional problem from Striver Sheet.
- Same as Sliding Window Maximum but with reversed logic.

----------------------------------------
🔹 Approach: Monotonic Deque
----------------------------------------

Maintain deque storing indices:
- Increasing order (small → large)
- Front = minimum element

Steps:
1. Remove out-of-window indices
2. Remove larger elements from back
3. Push current index
4. Store answer when window is valid

----------------------------------------
🔹 Complexity:
----------------------------------------

Time: O(n)
Space: O(k)

----------------------------------------
🔹 Tags:
----------------------------------------

#SlidingWindow #Deque #MonotonicQueue #StriverSheet
*/

class Solution {
public:
    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;      // stores indices
        vector<int> ans;    

        for (int i = 0; i < nums.size(); i++) {

            // 1. Remove elements out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain increasing order (REMOVE BIGGER ELEMENTS)
            while (!dq.empty() && nums[dq.back()] > nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Store result
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
