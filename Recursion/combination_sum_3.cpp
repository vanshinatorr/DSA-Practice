

/*
    Problem: Combination Sum III
    Platform: LeetCode 216
https://leetcode.com/problems/combination-sum-iii/submissions/2007967484/
    ---------------------------------------------------
    Problem Statement:
    Find all valid combinations of k numbers that sum up to n
    such that:
        - Only numbers from 1 to 9 are used
        - Each number is used at most once

    ---------------------------------------------------
    Approach:
    We use Backtracking / Recursion.

    At every step:
        1. Pick current number
        2. Move to next index using (i + 1)
           so duplicates are avoided
        3. Reduce target
        4. Backtrack using pop_back()

    ---------------------------------------------------
    Important Logic:
    function(i + 1, ...)
        -> Ensures next recursion starts from
           next number only.

    Example:
        pick 1 -> next starts from 2
        pick 2 -> next starts from 3

    This avoids:
        [1,1,2]
        [2,2,3]

    ---------------------------------------------------
    Pruning Optimization:
    if(i > target) break;

    Why?
    Because numbers after i will be even larger,
    so target can never become 0.

    ---------------------------------------------------
    Time Complexity:
    Roughly O(2^9)

    Space Complexity:
    O(k) recursion stack
*/

class Solution {
public:

    void solve(int start,
               int k,
               int target,
               vector<int>& ans,
               vector<vector<int>>& finalAns) {

        // Valid combination found
        if (target == 0 && ans.size() == k) {
            finalAns.push_back(ans);
            return;
        }

        // Invalid case
        if (target < 0 || ans.size() == k) {
            return;
        }

        // Try all possible numbers
        for (int i = start; i <= 9; i++) {

            // Pruning
            if (i > target)
                break;

            // Pick
            ans.push_back(i);

            // Move to next number
            solve(i + 1,
                  k,
                  target - i,
                  ans,
                  finalAns);

            // Backtrack
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> ans;
        vector<vector<int>> finalAns;

        solve(1, k, n, ans, finalAns);

        return finalAns;
    }
};
