/*

Problem: 35. Search Insert Position
Platform: LeetCode
Difficulty: Easy
Approach: Binary Search (Lower Bound)


Problem Statement:
Given a sorted array of distinct integers and a target value,
return the index if the target is found.
If not found, return the index where it would be inserted
in sorted order.

Constraint:
You must write an algorithm with O(log n) time complexity.

----------------------------------------------------

Approach:
This problem is a direct application of the concept of
"Lower Bound".

Lower Bound:
- Find the first index such that nums[index] >= target.
- If target exists, this index is its position.
- If target does not exist, this index is the correct
  insertion position.

We use Binary Search to achieve O(log n) time.

----------------------------------------------------

Time Complexity:
- O(log n)

Space Complexity:
- O(1)

-----------------------------------------------------
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;   // default insertion position

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;        
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }

        return ans;
    }
};
