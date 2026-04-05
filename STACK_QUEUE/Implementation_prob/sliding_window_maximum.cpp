/*
----------------------------------------
🔹 Problem: Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/submissions/1969770600/
----------------------------------------

Given an array nums and window size k,
return max of each sliding window.

Example:
nums = [1,3,-1,-3,5,3,6,7], k = 3
Output = [3,3,5,5,6,7]

----------------------------------------
🔹 Approach: Monotonic Deque (Optimal)
----------------------------------------

Maintain a deque storing INDICES:
- Deque is maintained in decreasing order of values
- Front = maximum element of current window

Steps:
1. Remove indices out of current window (i - k)
2. Remove all smaller elements from back (useless)
3. Push current index
4. Add front value to answer when window is valid

----------------------------------------
🔹 Complexity
----------------------------------------
Time: O(n)  → each element pushed & popped once
Space: O(k)

----------------------------------------
🔹 Tags
----------------------------------------
#SlidingWindow #Deque #MonotonicQueue #Hard
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;      // stores indices
        vector<int> ans;    // result

        for (int i = 0; i < nums.size(); i++) {

            // 1. Remove indices out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Store result when window is valid
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
