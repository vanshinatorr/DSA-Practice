/*
==========================================================
Problem:
Print Maximum Sum Subarray (Kadane's Algorithm)

Used In:
1. LeetCode 53 - Maximum Subarray
2. Print Maximum Sum Subarray
3. Variations of Kadane's Algorithm
4. Interview favorite O(n) optimization question

Core Idea:
Negative prefix kabhi future answer improve nahi kar sakta.

Example:
[-5, 3]

(-5 + 3 = -2) < 3

Isliye:

if(sum < 0)
    sum = 0;

==========================================================

MOST IMPORTANT ORDER

if(sum == 0)
    start = i;

sum += nums[i];

if(sum > maximum)
{
    maximum = sum;
    ansStart = start;
    ansEnd = i;
}

if(sum < 0)
    sum = 0;

Order galat hua to:
1. All negative cases fail ho sakte hain.
2. Wrong start/end indices aa sakte hain.

==========================================================

Why start = i ?

Jab previous iteration me:

sum < 0
sum = 0

ho gaya.

To next iteration me current index se
new subarray start hogi.

Isliye:

if(sum == 0)
    start = i;

==========================================================

Why maximum update BEFORE reset ?

Correct:

sum += nums[i];

maximum = max(maximum, sum);

if(sum < 0)
    sum = 0;

Example:

[-5,-2,-8]

Agar pehle reset kar diya:

sum = 0

To answer galat 0 aa jayega.

==========================================================

Complexity

Time  : O(n)
Space : O(1)

==========================================================
*/

class Solution {
public:
    vector<int> maximumSubarray(vector<int>& nums) {

        int sum = 0;
        int maximum = INT_MIN;

        int start = 0;
        int ansStart = 0;
        int ansEnd = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum == 0)
                start = i;

            sum += nums[i];

            if (sum > maximum) {
                maximum = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0)
                sum = 0;
        }

        vector<int> ans;

        for (int i = ansStart; i <= ansEnd; i++)
            ans.push_back(nums[i]);

        return ans;
    }
};
