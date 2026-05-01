


/*
---------------------------------------------------------
🔹 Problem: Move Zeroes (Leetcode 283)
https://leetcode.com/problems/move-zeroes/submissions/1841039578/


🔹 Description:
Given an integer array nums, move all 0's to the end 
while maintaining the relative order of non-zero elements.

Constraints:
- Do it in-place
- Do not make a copy of the array

Example:
Input:  [0,1,0,3,12]
Output: [1,3,12,0,0]

---------------------------------------------------------
🔹 Approach (Two Pointer Technique):

1. Maintain a pointer `j` → next position for non-zero element
2. Traverse array using pointer `i`
3. If nums[i] != 0:
      → swap(nums[i], nums[j])
      → increment j
4. Zeros automatically shift to the end

---------------------------------------------------------
🔹 Intuition:

Instead of moving zeros, we bring all non-zero elements forward.
This preserves order and avoids unnecessary shifting.

---------------------------------------------------------
🔹 Time Complexity:  O(n)
🔹 Space Complexity: O(1)

---------------------------------------------------------
🔹 Edge Cases:
- All elements are zero
- No zero in array
- Single element array

---------------------------------------------------------
🔹 Mistakes to Avoid:
- Shifting elements manually (O(n²))
- Overwriting values incorrectly
- Forgetting order maintenance

---------------------------------------------------------
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0; // next position for non-zero

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {

                // avoid unnecessary swap
                if (i != j) {
                    swap(nums[i], nums[j]);
                }

                j++;
            }
        }
    }
};
```
