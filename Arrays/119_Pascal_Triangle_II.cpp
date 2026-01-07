// LeetCode 119 - Pascal's Triangle II
// Approach: Build Pascal's Triangle row by row (same logic as full triangle)
// and return only the required row.
//
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> ans;

        for (int i = 0; i <= rowIndex; i++) {

            // Create current row with all elements initialized to 1
            vector<int> row(i + 1, 1);

            // Fill middle elements using Pascal's rule
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        // Return only the required row
        return ans[rowIndex];
    }
};
