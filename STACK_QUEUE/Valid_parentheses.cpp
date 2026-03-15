/* 
Problem: Valid Parentheses
Platform: LeetCode
https://leetcode.com/problems/valid-parentheses/


Problem Summary:
Given a string containing only '(', ')', '{', '}', '[' and ']',
check whether the brackets are valid.

Conditions:
1. Opening brackets must be closed by the same type.
2. Opening brackets must be closed in correct order.
3. Every closing bracket must have a matching opening bracket.

Approach (Stack):
- Traverse the string
- Push opening brackets into stack
- When closing bracket appears:
     check stack empty → invalid
     compare with stack top
     mismatch → invalid
     else pop
- At the end stack must be empty

Edge Cases:
1. Starting with closing bracket  -> ")()"
2. Mismatched brackets           -> "(]"
3. Extra opening brackets        -> "((("

Time Complexity: O(n)
Space Complexity: O(n)

Revision Notes:
- Classic stack problem
- Very common interview question
- Pattern also used in:
     Next Greater Element
     Daily Temperatures
     Largest Rectangle in Histogram
*/
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {

                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if (s[i] == ')' && top != '(') return false;
                if (s[i] == '}' && top != '{') return false;
                if (s[i] == ']' && top != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
