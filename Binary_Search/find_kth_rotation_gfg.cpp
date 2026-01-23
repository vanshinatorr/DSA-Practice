/*
Problem: Find Kth Rotation (GeeksforGeeks)     https://www.geeksforgeeks.org/problems/rotation4723/1

Given a sorted array which is rotated k times,
find the value of k (number of rotations).

Key Idea:
- Rotation count = index of the minimum element
- Use Binary Search (array has DISTINCT elements)

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {

            // If current subarray is already sorted
            if (arr[low] <= arr[high]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                low = mid + 1;
            }
            // Right half sorted
            else {
                if (arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;  // rotation count
    }
};





// Yahan hum arr[low] ko directly minimum nahi maan sakte.
// arr[low] sirf CURRENT sorted part ka minimum hai,
// ho sakta hai REAL minimum pehle hi mil chuka ho.
//
// Isliye:
// - pehle compare karte hain arr[low] < ans
// - agar haan, tabhi ans update karte hain
// - aur saath me index = low store karte hain
//
// min(ans, arr[low]) sirf value deta hai,
// lekin hume value + uska index dono chahiye.
