/*
LeetCode 154: Find Minimum in Rotated Sorted Array II withb duplicate 
leectode 153 wuthout dupicates 

Problem:
Given a rotated sorted array that may contain duplicates,
return the minimum element.

Approach (Binary Search with Duplicates Handling):
- Use modified binary search.
- At each step:
  1. Compute mid.
  2. If nums[low] == nums[mid] == nums[high],
     we cannot determine the sorted half due to duplicates,
     so shrink the boundaries (low++, high--).
  3. If left half is sorted (nums[low] <= nums[mid]),
     then nums[low] is a candidate for minimum.
     Move to the right half.
  4. Else, right half is sorted,
     so nums[mid] is a candidate for minimum.
     Move to the left half.

Important Note:
- We do NOT use the "whole array already sorted" shortcut,
  because it is unsafe when duplicates are present
  (e.g., [3,1,3]).

Time Complexity:
- Average case: O(log n)
- Worst case (all elements same): O(n)  [unavoidable]

Space Complexity:
- O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Duplicate ambiguity case
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[mid]);
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
