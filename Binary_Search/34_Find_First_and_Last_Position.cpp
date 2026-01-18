/*
====================================================
Problem: 34. Find First and Last Position of Element
Platform: LeetCode
Difficulty: Medium
Approach: Binary Search (Striver Style)
====================================================

Problem Statement:
Given a sorted array of integers nums and a target value,
return the starting and ending position of the target.

If the target is not found, return [-1, -1].

----------------------------------------------------

Approach (Striver Style):
We perform Binary Search twice:

1. First Occurrence:
   - When target is found, store the index
   - Continue searching on the left side

2. Last Occurrence:
   - When target is found, store the index
   - Continue searching on the right side

Why two searches?
- Normal binary search stops at first match
- Here we need boundary positions

----------------------------------------------------

Return Format:
We return a vector of size 2:
- ans[0] → first occurrence
- ans[1] → last occurrence

Vector is used because a function can return only one object.

----------------------------------------------------

Time Complexity:
- O(log n)

Space Complexity:
- O(1)

====================================================
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> ans(2, -1);   // default answer [-1, -1]

        // ---------- First Occurrence ----------
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;          // store index
                high = mid - 1;       // move left
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Target not found
        if (first == -1) return ans;

        // ---------- Last Occurrence ----------
        low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;           // store index
                low = mid + 1;        // move right
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        ans[0] = first;
        ans[1] = last;

        return ans;
    }
};
