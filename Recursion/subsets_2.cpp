// File: subsets_ii.cpp
https://leetcode.com/problems/subsets-ii/description/
/*
    Problem: Subsets II
    Platform: LeetCode

    Problem Statement:
    Given an integer array nums that may contain duplicates,
    return all possible subsets (the power set) without duplicate subsets.

    Example:
    Input:  nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    ------------------------------------------------------------

    Approach:
    1. Sort the array so duplicates become adjacent.
    2. Use Backtracking / Recursion.
    3. At every index:
         - Include current element
         - Exclude current element
    4. While excluding, skip all consecutive duplicates
       to avoid generating duplicate subsets.

    ------------------------------------------------------------

    Key Backtracking Idea:

        include current element
                |
             recurse
                |
            backtrack
                |
        exclude current element
                |
        skip duplicates
                |
             recurse

    ------------------------------------------------------------

    Time Complexity:
        O(2^n)

    Space Complexity:
        O(n) recursion stack
        (excluding answer storage)

    ------------------------------------------------------------

    Common Mistakes:
    1. Forgetting to sort the array
    2. Forgetting backtracking (pop_back)
    3. Skipping duplicates in wrong place
    4. Using i instead of i+1 causing infinite recursion

*/

class Solution {
public:

    void generateSubsets(
        int i,
        vector<int>& nums,
        vector<int>& current,
        vector<vector<int>>& result
    ) {

        // Base Case
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        // ---------------- INCLUDE ----------------

        current.push_back(nums[i]);

        generateSubsets(i + 1, nums, current, result);

        // Backtrack
        current.pop_back();

        // ---------------- EXCLUDE ----------------

        int nextIndex = i + 1;

        // Skip duplicates
        while (
            nextIndex < nums.size() &&
            nums[nextIndex] == nums[nextIndex - 1]
        ) {
            nextIndex++;
        }

        generateSubsets(nextIndex, nums, current, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Important for duplicate handling
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        generateSubsets(0, nums, current, result);

        return result;
    }
};
