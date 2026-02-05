/*
===========================================================
Problem: Search in 2D Matrix
Platform: LeetCode / Binary Search on 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/submissions/1909325439/

Problem Statement:
You are given an m x n integer matrix with the following properties:

1. Each row is sorted in ascending order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target exists in the matrix, otherwise false.

-----------------------------------------------------------
Approach:
Since the matrix is globally sorted, we can treat it like a
1D sorted array of size (rows * cols).

We apply Binary Search on index range [0, rows*cols - 1].

To convert 1D index into 2D coordinates:

row = index / cols
col = index % cols

We compare the matrix value with target and adjust the
binary search range accordingly.

-----------------------------------------------------------
Time Complexity:
O(log(rows * cols))

Space Complexity:
O(1)

===========================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Edge case: empty matrix
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int r = mid / cols;
            int c = mid % cols;

            int value = matrix[r][c];

            if (value == target)
                return true;

            if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};
