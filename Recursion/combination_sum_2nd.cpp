/*
========================================================
LeetCode 40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/submissions/2007355498/
========================================================

Problem:
Given a collection of candidate numbers and a target,
find all unique combinations where the chosen numbers
sum to target.

Rules:
- Each index can be used only once.
- Duplicate combinations are not allowed.

--------------------------------------------------------
Approach:
1. Sort the array.
2. Use recursion + backtracking.
3. At every index:
   - PICK current element
   - NOT PICK current element
4. While doing NOT PICK:
   skip all duplicates to avoid repeated combinations.

--------------------------------------------------------
Key Intuition:
- Same VALUE can be picked multiple times
  IF they are at different indices.
- Same INDEX cannot be reused.

Example:
[1,1,1,2]

Valid:
- pick index 0
- pick index 1
- pick index 2

Invalid:
- reuse same index again

--------------------------------------------------------
Duplicate Handling:
Duplicate skipping happens ONLY in NOT PICK branch.

Why?
Because:
If first 1 is skipped,
starting recursion from second 1
would generate same combinations again.

--------------------------------------------------------
Time Complexity:
O(2^N)

Space Complexity:
O(N) recursion stack
(excluding answer space)

========================================================
*/

class Solution {
public:

    void solve(int index,
               int target,
               vector<int>& candidates,
               vector<int>& ans,
               vector<vector<int>>& finalAns,
               int n)
    {
        // Base Case
        if (target == 0) {
            finalAns.push_back(ans);
            return;
        }

        // Invalid Case
        if (index >= n || target < 0) {
            return;
        }

        /*
        ====================================================
        PICK CURRENT ELEMENT
        ====================================================
        */

        ans.push_back(candidates[index]);

        solve(index + 1,
              target - candidates[index],
              candidates,
              ans,
              finalAns,
              n);

        // Backtrack
        ans.pop_back();

        /*
        ====================================================
        NOT PICK CURRENT ELEMENT
        ====================================================
        Skip duplicates before moving ahead
        ====================================================
        */

        int indx = index + 1;

        while (indx < n &&
               candidates[indx] == candidates[indx - 1])
        {
            indx++;
        }

        solve(indx,
              target,
              candidates,
              ans,
              finalAns,
              n);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target)
    {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();

        vector<int> ans;
        vector<vector<int>> finalAns;

        solve(0,
              target,
              candidates,
              ans,
              finalAns,
              n);

        return finalAns;
    }
};
