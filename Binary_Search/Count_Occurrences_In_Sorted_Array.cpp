/*
====================================================
Que Link : https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456
----------------------------------------------------
Problem: Count Occurrences of X in a Sorted Array
Platform: Code360 / Coding Ninjas
Difficulty: Medium
Approach: Binary Search (Striver Style)
====================================================

Problem Statement:
Given a sorted array 'arr' of size 'n' and an integer 'x',
find the total number of occurrences of 'x' in the array.

----------------------------------------------------

Approach:
The problem is solved using Binary Search in two steps:

1. First Occurrence:
   - When arr[mid] == x, store index
   - Continue searching on the left side

2. Last Occurrence:
   - When arr[mid] == x, store index
   - Continue searching on the right side

Total Count:
count = lastOccurrence - firstOccurrence + 1

If x is not present, return 0.

----------------------------------------------------

Time Complexity:
- O(log n)

Space Complexity:
- O(1)

====================================================
*/

int count(vector<int>& arr, int n, int x) {
    
    // ---------- First Occurrence ----------
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            first = mid;        // store index
            high = mid - 1;     // move left
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // x not present in array
    if (first == -1) return 0;

    // ---------- Last Occurrence ----------
    low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            last = mid;         // store index
            low = mid + 1;      // move right
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // Total number of occurrences
    return last - first + 1;
}
