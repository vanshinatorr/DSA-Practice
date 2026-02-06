/*
===========================================================
LeetCode 240 — Search a 2D Matrix II
https://leetcode.com/problems/search-a-2d-matrix-ii/
File: search-2d-matrix-ii.cpp
===========================================================

Problem:
Given an m x n matrix where:

- Each row is sorted in ascending order (left → right)
- Each column is sorted in ascending order (top → bottom)

Return true if the target exists in the matrix, otherwise false.

-----------------------------------------------------------
Approach — Top Right Search (Greedy Elimination)

We start from the top-right corner of the matrix.

Why top-right?

- Left → smaller values
- Down → larger values

At each step:

1. If current == target → found
2. If current > target → move left
3. If current < target → move down

Each move eliminates one row or column.

-----------------------------------------------------------
Time Complexity:  O(n + m)
Space Complexity: O(1)

n = rows, m = columns
-----------------------------------------------------------
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Start from top-right corner
        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0) {

            int current = matrix[row][col];

            if (current == target)
                return true;

            else if (current < target)
                row++;      // move down

            else
                col--;      // move left
        }

        return false;
    }
};
