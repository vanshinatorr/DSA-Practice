/*
Problem:
Search in a rotated sorted array that may contain duplicates.
This solution works for:
- LeetCode 33 (no duplicates)   https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
- LeetCode 81 (duplicates allowed)  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

Approach:
We use a modified Binary Search.
At each step:
1. Calculate mid.
2. If nums[mid] == target, return mid.
3. If nums[low], nums[mid], and nums[high] are equal, we cannot determine
   the sorted half, so we shrink the boundaries (low++, high--).
4. Otherwise, determine which half is sorted:
   - If left half is sorted, check if target lies in it.
   - Else, right half must be sorted; check target there.
5. Narrow the search space accordingly.

Why boundary shrinking?
Duplicates can make both halves look sorted, so shrinking avoids ambiguity.

Time Complexity:
- Average case: O(log n)
- Worst case (all elements same): O(n)  [unavoidable due to duplicates]

Space Complexity:
- O(1), iterative binary search

Note:
This single implementation passes both LC 33 and LC 81.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // Duplicate case: cannot decide sorted half
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Left half sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Right half sorted
            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
