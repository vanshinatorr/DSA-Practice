/*
    Problem: Rotate Array
    Platform: LeetCode 189

    ----------------------------------------------------

    📌 Revision Note

    Is question ke mainly 2 approaches hote hain:

    1️⃣ Extra Array Approach
    - Easy to understand
    - Extra space O(N)

    2️⃣ Reverse Technique ✅
    - Optimal approach
    - O(1) extra space
    - Interview preferred

    Maine ye reverse wala approach use kiya
    because array ko 3 reverses me directly rotate
    kar sakte hain without extra array.

    ----------------------------------------------------

    Example:

    nums = [1,2,3,4,5,6,7]
    k = 3

    Step 1:
    Reverse complete array

    [7,6,5,4,3,2,1]

    Step 2:
    Reverse first k elements

    [5,6,7,4,3,2,1]

    Step 3:
    Reverse remaining elements

    [5,6,7,1,2,3,4]

    ----------------------------------------------------

    ⚠️ Important

    k can be greater than n

    Example:
    n = 7
    k = 10

    So:
    k = k % n

    ----------------------------------------------------

    Time Complexity:
    O(N)

    Space Complexity:
    O(1)

*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Handle large k
        k = k % n;

        // Reverse complete array
        reverse(nums.begin(), nums.end());

        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
