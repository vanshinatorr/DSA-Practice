/*
========================================================
LeetCode 3211 

Generate Binary Strings Without Adjacent Zeroes

https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/



Also:
This generation version is MORE IMPORTANT than the counting version
because:
- It builds actual recursion understanding
- Helps visualize recursion trees
- Creates foundation for backtracking
- Counting problems become easier after this

========================================================

PROBLEM:
Generate all binary strings of length n
such that no two consecutive zeroes exist.

Example:
n = 2

Output:
11
10
01

Invalid:
00

========================================================

APPROACH:
At every step we have 2 choices:

1. Add '1'
   -> Always allowed

2. Add '0'
   -> Allowed only if previous character is NOT '0'

We recursively build strings until length becomes n.

========================================================

RECURSION TREE (n = 2)

""
├── "1"
│   ├── "11" ✅
│   └── "10" ✅
└── "0"
    ├── "01" ✅
    └── ❌ "00"

========================================================

TIME COMPLEXITY:
O(2^n)

SPACE COMPLEXITY:
O(n)
(recursion stack)

========================================================
*/

class Solution {
public:

    void solve(int n, string curr, vector<string>& ans) {

        // Base Case:
        // If current string length becomes n,
        // store the string in answer vector
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        // ------------------------------------------------
        // Choice 1:
        // Add '1'
        // Always allowed
        // ------------------------------------------------
        solve(n, curr + '1', ans);

        // ------------------------------------------------
        // Choice 2:
        // Add '0'
        // Only if previous character is not '0'
        // ------------------------------------------------
        if (curr.empty() || curr.back() != '0') {
            solve(n, curr + '0', ans);
        }
    }

    vector<string> validStrings(int n) {

        // Final answer container
        vector<string> ans;

        // Start recursion with empty string
        solve(n, "", ans);

        return ans;
    }
};
