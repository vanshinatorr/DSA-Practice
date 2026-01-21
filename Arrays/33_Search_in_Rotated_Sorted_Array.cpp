// 33. Search in Rotated Sorted Array
// LeetCode - Medium : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//
// Approach 
// - Use Binary Search since O(log n) is required.
// - In a rotated sorted array, at least one half (left or right) is always sorted.
// - Steps:
//   1. Find mid.
//   2. If nums[mid] == target → return mid.
//   3. Check which half is sorted:
//      a) Left half sorted → nums[low] <= nums[mid]
//      b) Right half sorted → otherwise
//   4. Check if target lies in the sorted half:
//      - If yes → search that half
//      - If no → search the other half
// - If not found, return -1.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
