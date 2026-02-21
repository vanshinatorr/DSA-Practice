/*
=========================================================
LeetCode 88 - Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
Approach: 3 Pointer Reverse Merge
Author: Vansh Vijay
=========================================================

🔹 Problem:
Merge two sorted arrays into nums1 in-place.
nums1 has enough space (size = m + n).

---------------------------------------------------------
🔹 Approach (Reverse 3-Pointer Technique):

1. Start filling from the back to avoid overwriting.
2. Use three pointers:
   - i → last valid element of nums1 (m - 1)
   - j → last element of nums2 (n - 1)
   - k → last index of nums1 (m + n - 1)

3. Compare nums1[i] and nums2[j]
   - Place the larger element at nums1[k]
   - Move corresponding pointer backward

4. If nums2 still has elements left,
   copy them into nums1.

---------------------------------------------------------
🔹 Why Reverse Merge?

- Forward merge would overwrite elements in nums1.
- Reverse merge avoids extra space.
- Works in O(1) additional space.

---------------------------------------------------------
🔹 Time Complexity:
O(m + n)
Each element is processed exactly once.

🔹 Space Complexity:
O(1)
No extra array used.

---------------------------------------------------------
🔹 Key Concepts:
- Always fill from the end.
- Only nums2 leftover needs handling.
- i leftover case is unnecessary because
  elements are already in correct position.
=========================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;        // Last valid element in nums1
        int j = n - 1;        // Last element in nums2
        int k = m + n - 1;    // Last index of nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        // If nums2 still has elements left
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }

        /*
        i case is unnecessary:
        If nums1 elements remain,
        they are already in correct position.
        */
        while (i >= 0) {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
    }
};
