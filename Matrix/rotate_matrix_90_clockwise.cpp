// LeetCode 48 - Rotate Image
// Time Complexity: O(n^2)
// Space Complexity: O(1)  (in-place)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};



/*
NOTE:
This problem uses a square matrix (n x n).
matrix.size() gives both rows and columns.
90° in-place rotation is not possible for rectangular matrices.
*/
