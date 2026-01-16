/*
# Implement Lower Bound using Binary Search

## 📌 Problem Statement
Given a **sorted array** `arr` of size `n` and an integer `x`,  
find the **lower bound** of `x`.
**Lower Bound** is defined as the **first index** such that:
arr[index] ≥ x
If no such index exists, return `n`.

## 🔍 Examples

Input:
arr = [1, 2, 4, 4, 6], x = 4  
Output: 2

Input:
arr = [1, 2, 4, 6], x = 5  
Output: 3

Input:
arr = [1, 2, 3], x = 10  
Output: 3

# Approach
Since the array is sorted, we use Binary Search

### Logic:
- If `arr[mid] ≥ x`  
  → mid can be a possible answer  
  → store it and move left
- If `arr[mid] < x`  
  → lower bound must be on the right side

We initialize `ans = n` to handle cases where no valid index exists.
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {

    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
