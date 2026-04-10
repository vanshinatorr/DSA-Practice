
    /*
    🧩 Remove Outer Parentheses

    📌 Problem: Easy
    https://leetcode.com/problems/remove-outermost-parentheses/submissions/1974386949/
    Given a valid parentheses string, remove the outermost parentheses of each primitive substring.

    💡 Approach:
    - Use depth counter
    - '('  → add if depth > 0, then depth++
    - ')'  → depth--, then add if depth > 0

    🧠 Key Insight:
    - Skip when going 0 → 1 (outer start)
    - Skip when going 1 → 0 (outer end)

    ⚙️ Complexity:
    - Time: O(n)
    - Space: O(1)

    🔁 Example:
    Input:  (())
    Output: ()

    ❗ Mistakes:
    - '=' instead of '=='
    - Wrong order of depth update
    */

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) result.push_back(ch);
                depth++;
            } else {
                depth--;
                if (depth > 0) result.push_back(ch);
            }
        }
        return result;
    }
};
