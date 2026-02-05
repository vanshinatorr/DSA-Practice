/*
========================================================
Problem: Row with Maximum 1s
Platform: CodeStudio / Binary Search on 2D Arrays
Approach: Binary Search per Row (Striver approach)
Time Complexity: O(n log m)
Space Complexity: O(1)

Idea:
Each row is sorted (0s → 1s).
We binary search to find the first occurrence of 1.
Number of 1s = m - first_index.
Track the row with maximum count.

========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>& arr, int n, int x) {

    int low = 0;
    int high = arr.size() - 1;
    int ans = n;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {

    int cnt_max = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {

        int first_one = lowerbound(matrix[i], m, 1);
        int cnt_ones = m - first_one;

        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }

    return index;
}
