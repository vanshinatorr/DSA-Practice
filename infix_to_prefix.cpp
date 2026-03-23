
/*
------------------------------------------------------------
📌 Problem: Convert Infix Expression to Prefix Expression

https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1
solved on GFG
LITTE BIT COMPLEX EDGE CASES OTHERWISE SAME AS INFIX TO POSTFIX
------------------------------------------------------------
🧠 Approach: Striver Method (Reverse + Postfix + Reverse)

Steps:
1. Reverse the input string
2. Swap brackets '(' ↔ ')'
3. Apply modified Infix → Postfix logic
4. Reverse the result to get Prefix

------------------------------------------------------------
📊 Operator Precedence:

^   → 3  (Right Associative)
* / → 2
+ - → 1

------------------------------------------------------------
⚠️ Key Insight:

- For '^' (right associative):
  → pop when precedence is equal

- For '+ - * /' (left associative):
  → do NOT pop when equal precedence

------------------------------------------------------------
⏱️ Time Complexity:
O(N)

💾 Space Complexity:
O(N)

------------------------------------------------------------
🚀 Example:

Input:  (a+b)*c
Output: *+abc

Input:  a+b*c
Output: +a*bc

------------------------------------------------------------
*/

class Solution {
public:
    // Function to return precedence of operators
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPrefix(string &s) {
        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());

        // Step 2: Swap brackets
        // '(' becomes ')' and ')' becomes '('
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }

        stack<char> st;
        string ans = "";

        // Step 3: Modified Infix to Postfix logic
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If operand, add to result string
            if (isalnum(c)) {
                ans += c;
            }
            // If opening bracket, push to stack
            else if (c == '(') {
                st.push(c);
            }
            // If closing bracket, pop until opening bracket is found
            else if (c == ')' ) {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Pop '('
            }
            // If operator is encountered
            else {
                /* 
                   Special condition for Prefix conversion via reversal:
                   1. Pop if top precedence is GREATER than current.
                   2. Pop if precedence is EQUAL only if operator is '^' (Right-to-Left).
                   3. Otherwise, for + - * / (Left-to-Right), keep on stack if precedence is equal.
                */
                while (!st.empty() && (precedence(st.top()) > precedence(c) || 
                      (precedence(st.top()) == precedence(c) && c == '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all remaining operators from stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse the final string to get Prefix notation
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

