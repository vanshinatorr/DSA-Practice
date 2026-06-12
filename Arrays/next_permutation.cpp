/*
===============================================================================
Problem      : Next Permutation
Platform     : LeetCode 31
Difficulty   : Medium
https://leetcode.com/problems/next-permutation/
===============================================================================

Problem:
Given an array representing a permutation of numbers,
transform it into the next lexicographically greater permutation.

If such a permutation does not exist,
rearrange it into the lowest possible order (ascending order).

Examples:

Input  : [1,2,3]
Output : [1,3,2]

Input  : [3,2,1]
Output : [1,2,3]

Input  : [1,1,5]
Output : [1,5,1]

===============================================================================
Approach (Optimal)

Observation:

To get the next lexicographically greater permutation,
we should make the smallest possible increase.

Steps:

1. Find the Break Point (Pivot)
   - Traverse from right to left.
   - Find first index where:
         nums[i] > nums[i - 1]
   - Store (i - 1) as pivot.

2. If No Pivot Exists
   - Array is completely descending.
   - Current permutation is the largest possible permutation.
   - Reverse the whole array to get the smallest permutation.

3. Find Next Greater Element
   - Traverse from right side.
   - Find first element greater than pivot value.
   - Swap with pivot.

4. Reverse the Suffix
   - Elements after pivot are in descending order.
   - Reverse them to obtain the smallest possible suffix.

===============================================================================
Why It Works

After finding the pivot:

[prefix] [pivot] [descending suffix]

The suffix is already the largest arrangement.

To create the next permutation:

1. Increase the pivot by swapping it with the smallest element
   greater than it from the right side.

2. Convert the suffix into its smallest arrangement
   by reversing it.

This guarantees the immediate next lexicographical permutation.

===============================================================================
Dry Run

Input:
1 2 7 4 3 1

Pivot:
2 (index = 1)

Find next greater from right:
3

Swap:
1 3 7 4 2 1

Reverse suffix:
1 3 1 2 4 7

Answer:
1 3 1 2 4 7

===============================================================================
Complexity

Time Complexity  : O(n)
Space Complexity : O(1)

===============================================================================
Interview Notes

Key Observation:
After the pivot, the suffix is always in descending order.

Why reverse works?
Because a descending sequence reversed becomes ascending,
which is the smallest possible arrangement.

Common Pattern:
- Lexicographical ordering
- Permutation generation
- Greedy + Array manipulation

Common Mistakes:

1. Forgetting the index == -1 case.
2. Reversing from pivot instead of pivot + 1.
3. Searching next greater element from left side.
4. Sorting suffix instead of reversing.
   (reverse is enough because suffix is already descending)

===============================================================================
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int index = -1;

        // Step 1: Find Pivot
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i - 1;
                break;
            }
        }

        // Step 2: Largest permutation case
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element from right
        for (int i = n - 1; i > index; i--) {
            if (nums[index] < nums[i]) {
                swap(nums[index], nums[i]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
