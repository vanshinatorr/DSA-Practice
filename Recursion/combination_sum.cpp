
/*
========================================
            Combination Sum  (leetcode 39)
 https://leetcode.com/problems/combination-sum/
========================================

Problem:
Given an array of distinct integers candidates and a target integer target,
return all unique combinations where the chosen numbers sum to target.

You may use the same number unlimited times.

----------------------------------------
Example:
Input:
candidates = [2,3,6,7]
target = 7

Output:
[
  [2,2,3],
  [7]
]

----------------------------------------
Approach:
We use Recursion + Backtracking.

At every index, we have 2 choices:

1. Pick the current element
   - Add it to current combination
   - Reduce target
   - Stay on same index
     because same element can be reused

2. Skip the current element
   - Move to next index

Backtracking:
After recursive call, remove the element
to restore previous state.

----------------------------------------
Recursion Flow:

pick:
    push_back()
    recursive call
    pop_back()

not pick:
    recursive call

----------------------------------------
Base Cases:

1. target == 0
   Valid combination found

2. target < 0
   Invalid path

3. index >= n
   No elements left

----------------------------------------
Time Complexity:
Exponential (Backtracking)

Approx:
O(2^target)

----------------------------------------
Space Complexity:
O(target)
(recursion stack + current combination)

========================================
*/

class Solution {
public:

    void solve(vector<int>& candidates,
               int target,
               int index,
               vector<int>& ans,
               vector<vector<int>>& finalans,
               int n)
    {
        // Base Case:
        // Valid combination found
        if(target == 0) {
            finalans.push_back(ans);
            return;
        }

        // Base Case:
        // Invalid path
        if(index >= n || target < 0) {
            return;
        }

        // --------------------------------
        // PICK current element
        // --------------------------------
        ans.push_back(candidates[index]);

        solve(candidates,
              target - candidates[index],
              index,
              ans,
              finalans,
              n);

        // Backtracking
        ans.pop_back();

        // --------------------------------
        // NOT PICK current element
        // --------------------------------
        solve(candidates,
              target,
              index + 1,
              ans,
              finalans,
              n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();

        vector<int> ans;

        vector<vector<int>> finalans;

        solve(candidates,
              target,
              0,
              ans,
              finalans,
              n);

        return finalans;
    }
};
