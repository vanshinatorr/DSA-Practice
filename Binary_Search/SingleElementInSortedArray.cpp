//  Problem
// LeetCode 540 – Single Element in a Sorted Array      
// Link:  https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1895290510/


//  Approach 
// The array is sorted
// Every element appears exactly twice, except one
// Before the single element:
// Even index → paired with next index
// Odd index → paired with previous index
// After the single element, this even–odd pairing pattern breaks
// Use Binary Search to detect where the pattern breaks and move left/right accordingly



// ⏱ Complexity
// Time Complexity: O(log n)
// Space Complexity: O(1)



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If mid is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            /*
             Pairing rule:
             - Even index should match with next index
             - Odd index should match with previous index

             If pairing is correct → single element is on the RIGHT side
             If pairing is broken → single element is on the LEFT side
            */
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;   // move right
            } else {
                high = mid - 1;  // move left
            }
        }

        // Fallback return for compiler safety
        return -1;
    }
};
