/*
    Problem: Binary Search (LeetCode 704)
    Platform: LeetCode
    Difficulty: Easy

    Problem Statement:
    Given a sorted array of integers nums (in ascending order) and an integer target,
    return the index of target if it exists in nums.
    Otherwise, return -1.

    Approach:
    - Use iterative Binary Search.
    - Maintain two pointers: low and high.
    - Find mid and compare nums[mid] with target.
    - Reduce the search space by half in each iteration.

    Why Binary Search?
    - The array is sorted.
    - Binary Search reduces time complexity from O(n) to O(log n).

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            // Prevent overflow
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Target not found
        return -1;
    }
};
