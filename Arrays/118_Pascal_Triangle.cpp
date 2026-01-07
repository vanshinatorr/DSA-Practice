// LeetCode 118 - Pascal's Triangle
// Generate the first numRows of Pascal's Triangle
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // This 2D vector will store the complete Pascal's Triangle
        vector<vector<int>> ans;

        // Loop for each row
        for (int i = 0; i < numRows; i++) {

            // Create a row of size (i + 1) and initialize all values with 1
            vector<int> row(i + 1, 1);

            // Fill only the middle elements using Pascal's rule
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            // Add the current row to the final answer
            ans.push_back(row);
        }

        return ans;
    }
};
