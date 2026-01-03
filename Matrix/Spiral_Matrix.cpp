// Problem: Spiral Matrix
// Platform: LeetCode(54)
// Approach: Boundary + Count based traversal
// Time Complexity: O(n*m)
// Space Complexity: O(1) extra

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int total = row * col;
        int count = 0;

        int startingrow = 0, startingcol = 0;
        int endingrow = row - 1, endingcol = col - 1;

        while (count < total) {

            for (int j = startingcol; j <= endingcol && count < total; j++) {
                ans.push_back(matrix[startingrow][j]);
                count++;
            }
            startingrow++;

            for (int i = startingrow; i <= endingrow && count < total; i++) {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;

            for (int j = endingcol; j >= startingcol && count < total; j--) {
                ans.push_back(matrix[endingrow][j]);
                count++;
            }
            endingrow--;

            for (int i = endingrow; i >= startingrow && count < total; i--) {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }

        return ans;
    }
};
