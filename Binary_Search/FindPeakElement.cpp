//  Problem      https://leetcode.com/problems/find-peak-element/submissions/1895415425/

// Find Peak Element   
// Return the index of any peak element.
// A peak element is an element that is strictly greater than its neighbors.


//  Approach 
// A peak element always exists in the array.
// First, handle edge cases:
// If array size is 1 → index 0 is peak
// If first element is greater than second → index 0 is peak
// If last element is greater than second last → index n-1 is peak
// Apply binary search between indices 1 and n-2
// At each mid:
// If nums[mid] is greater than both neighbors → peak found
// If slope is rising (nums[mid] > nums[mid-1]) → peak lies on the right
// Else → peak lies on the left
// This works because at least one peak is always guaranteed.

  
// Complexity
// Time Complexity: O(log n)
// Space Complexity: O(1)



















#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one element
        if (n == 1)
            return 0;

        // Edge case: first element is a peak
        if (nums[0] > nums[1])
            return 0;

        // Edge case: last element is a peak
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        // Binary search range (safe from out-of-bounds)
        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid itself is a peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // If slope is rising, peak must be on the right
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            // If slope is falling, peak must be on the left
            else {
                high = mid - 1;
            }
        }

        // This return is for compiler safety (logically unreachable)
        return -1;
    }
};
