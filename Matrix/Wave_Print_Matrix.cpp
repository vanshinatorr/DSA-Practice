#include <bits/stdc++.h> 
using namespace std;

// Problem: Wave Print Matrix
// Approach: Column-wise traversal
// Time: O(n*m), Space: O(1)

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {

    vector<int> ans;

    for (int col = 0; col < mCols; col++) {

        // odd column -> bottom to top
        if (col % 2 != 0) {
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        // even column -> top to bottom
        else {
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
