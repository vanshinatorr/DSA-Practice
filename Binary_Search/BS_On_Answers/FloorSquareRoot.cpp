//  Problem : https://www.naukri.com/code360/problems/square-root_893351?utm_source=chatgpt.com&leftPanelTabValue=SUBMISSION
// solved on code 360 by naukri.com

// Floor Square Root of a Number   
// Given a non-negative integer n, find and return the floor value of √n.
// If n is not a perfect square, return the largest integer whose square is ≤ n.

// Approach (Binary Search)
// The square root of n always lies between 0 and n
// We apply binary search on the answer space
// At each step:
// Compute mid
// If mid * mid ≤ n, store mid as a possible answer and move right
// Else, move left
// Keep updating the last valid mid
// Handle small edge cases (n = 0 and n = 1) separately
// This works because mid * mid is a monotonic function.


// ⏱ Complexity
// Time Complexity: O(log n)
// Space Complexity: O(1)



#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    // Edge cases
    if (n == 0 || n == 1)
        return n;

    int low = 0;
    int high = n - 1;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square <= n) {
            ans = mid;        // possible answer
            low = mid + 1;    // try to find a bigger one
        } else {
            high = mid - 1;   // reduce search space
        }
    }

    return ans;
}
