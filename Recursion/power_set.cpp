// File: power_set_recursion.cpp

/*
========================================================
                POWER SET / SUBSETS
 https://leetcode.com/problems/subsets/description/?utm_source=chatgpt.com
========================================================

Problem:
Given an integer array nums of unique elements,
return all possible subsets (the power set).

Example:
Input:
nums = [1,2,3]

Output:
[
 [],
 [1],
 [2],
 [3],
 [1,2],
 [1,3],
 [2,3],
 [1,2,3]
]

--------------------------------------------------------
Approach:
We use Recursion + Backtracking.

For every element we have 2 choices:
1. Include the element
2. Exclude the element

At each index:
- Push the element into current subset
- Explore recursively
- Pop the element (Backtrack)
- Explore excluding that element

--------------------------------------------------------
Recursion Pattern:

choose
explore
undo

Code Form:

push_back()
recursive_call()
pop_back()

--------------------------------------------------------
Time Complexity:
O(2^N)

Reason:
Each element has 2 choices.

Total subsets = 2^N

--------------------------------------------------------
Space Complexity:
O(N)

Reason:
Recursion stack + temporary subset vector.

--------------------------------------------------------
Important Learning:
Backtracking means:
"Restore previous state after recursion."

Without pop_back(),
elements leak into other recursive branches.

========================================================
*/

class Solution {
public:

    void findSubset(int index,
                    vector<int>& nums,
                    vector<int>& currentSubset,
                    vector<vector<int>>& ans) {

        // ================= BASE CASE =================
        if (index == nums.size()) {
            ans.push_back(currentSubset);
            return;
        }

        // ==================================================
        //                 INCLUDE CURRENT ELEMENT
        // ==================================================

        currentSubset.push_back(nums[index]);

        findSubset(index + 1,
                   nums,
                   currentSubset,
                   ans);

        // ================= BACKTRACK =================
        currentSubset.pop_back();

        // ==================================================
        //                 EXCLUDE CURRENT ELEMENT
        // ==================================================

        findSubset(index + 1,
                   nums,
                   currentSubset,
                   ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> currentSubset;

        findSubset(0,
                   nums,
                   currentSubset,
                   ans);

        return ans;
    }
};


/*
========================================================
                    DRY RUN
========================================================

nums = [1,2]

Start:
currentSubset = []

--------------------------------
Include 1
currentSubset = [1]

    Include 2
    currentSubset = [1,2]

        Base Case
        Store [1,2]

    Backtrack
    currentSubset = [1]

    Exclude 2

        Base Case
        Store [1]

--------------------------------
Backtrack
currentSubset = []

Exclude 1

    Include 2
    currentSubset = [2]

        Base Case
        Store [2]

    Backtrack
    currentSubset = []

    Exclude 2

        Base Case
        Store []

========================================================
Final Answer:
[
 [1,2],
 [1],
 [2],
 []
]
========================================================
*/
