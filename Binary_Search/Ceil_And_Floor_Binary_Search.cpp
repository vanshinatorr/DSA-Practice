/*
====================================================
Problem: Ceil The Floor
Platform: Code360 (Coding Ninjas)
Difficulty: Easy
Approach: Binary Search (Without using STL)
====================================================

Problem Statement:
Given a sorted array 'a' of size 'n' and an integer 'x',
find the floor and ceil of 'x' in the array.

Floor:
- Largest element less than or equal to 'x'

Ceil:
- Smallest element greater than or equal to 'x'

If floor or ceil does not exist, return -1 for that value.

----------------------------------------------------

Approach:
We use Binary Search to efficiently find both floor and ceil.

- If a[mid] == x:
    - Floor and Ceil are both equal to x.
- If a[mid] < x:
    - a[mid] is a possible floor.
    - Move right to find a larger floor.
- If a[mid] > x:
    - a[mid] is a possible ceil.
    - Move left to find a smaller ceil.

----------------------------------------------------

Time Complexity:
- O(log n)

Space Complexity:
- O(1)

====================================================
*/

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

    int low = 0, high = n - 1;
    int floorVal = -1, ceilVal = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == x) {
            floorVal = a[mid];
            ceilVal = a[mid];
            break;
        }
        else if (x > a[mid]) {
            floorVal = a[mid];     // possible floor
            low = mid + 1;
        }
        else {
            ceilVal = a[mid];      // possible ceil
            high = mid - 1;
        }
    }

    return {floorVal, ceilVal};
}
