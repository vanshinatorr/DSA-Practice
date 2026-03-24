
/* Postfix to Infix Conversion 

https://www.naukri.com/code360/problems/postfix-to-infix_8382386?utm_source=chatgpt.com&leftPanelTabValue=SUBMISSION


Given a postfix expression consisting of alphabets and operators, convert it into a valid infix expression.
Every expression must be enclosed within parentheses.

----------------------------------------------

## 💡 Approach

* Use a stack of strings
* Traverse the postfix expression from left to right
* If the current character is an operand → push it as a string
* If the current character is an operator:

  * Pop top two elements from the stack
  * Form a new string: `(operand1 operator operand2)`
  * Push the result back to the stack
* The final element in the stack is the infix expression
------------------------------------------------

## ⚡ Complexity

* Time Complexity: O(n)
* Space Complexity: O(n)

-------------------------------------------------

## 🔁 Quick Revision

* Stack stores strings (expressions)
* Operand → push
* Operator → pop 2 → combine → push
* Final answer → st.top()
* Valid postfix → final stack size must be 1
----------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

string postToInfix(string postfix) {

    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();

            string temp = "(" + c2 + c + c1 + ")";
            st.push(temp);
        }
    }

    return st.top();
}
