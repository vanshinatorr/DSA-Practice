
/*
-------------------------------------------------------
Problem: Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function
to generate all combinations of well-formed parentheses.

Example:
Input: n = 3

Output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

-------------------------------------------------------
Approach:
- Use recursion + backtracking
- At every step we have 2 choices:
    1. Add '('
    2. Add ')'

Rules:
- We can add '(' only if open < n
- We can add ')' only if close < open

Base Case:
- If string size becomes n * 2
  -> valid answer found

-------------------------------------------------------
Time Complexity:
O(2^(2n)) approx

Space Complexity:
O(2n) recursion stack

-------------------------------------------------------
*/

class Solution {
public:

    void parentheses(string ans,
                     int close,
                     int open,
                     int n,
                     vector<string>& str) {

        // Base Case
        if (ans.size() == n * 2) {
            str.push_back(ans);
            return;
        }

        // Add Opening Bracket
        if (open < n) {
            parentheses(ans + "(",
                         close,
                         open + 1,
                         n,
                         str);
        }

        // Add Closing Bracket
        if (close < open) {
            parentheses(ans + ")",
                         close + 1,
                         open,
                         n,
                         str);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> str;

        // Initial Recursive Call
        parentheses("", 0, 0, n, str);

        return str;
    }
};
