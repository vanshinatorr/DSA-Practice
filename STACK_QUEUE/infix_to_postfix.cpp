

/*
------------------------------------------------------------
https://www.naukri.com/code360/problems/infix-to-postfix_1382146?leftPanelTabValue=SUBMISSION

📌 Problem: Convert Infix Expression to Postfix Expression

------------------------------------------------------------
🧠 Concept (Revision Notes):

Infix Expression:
👉 Operator operands ke beech me hota hai
Example: a + b

Postfix Expression:
👉 Operator operands ke baad aata hai
Example: ab+

------------------------------------------------------------
⚙️ Algorithm (Stack Based):

1. Operand (a-z, A-Z, 0-9):
   → Direct answer (ans) me add karo

2. '(' :
   → Stack me push karo

3. ')' :
   → Jab tak '(' na mile tab tak pop karke ans me add karo
   → '(' ko remove karo (ans me nahi add karte)

4. Operator (+, -, *, /, ^):
   → Jab tak stack ka top operator:
        - higher ya equal precedence ka ho
     → usse pop karke ans me add karo
   → current operator ko stack me push karo

5. End me:
   → Stack ke saare remaining operators ans me daal do


፧ try this striver example in rough 
      
      a+b*(c^d-e)
------------------------------------------------------------
📊 Precedence:

^  → 3 (highest)
* / → 2
+ - → 1

------------------------------------------------------------
⚠️ Important Points:

✔ Same precedence → left to right follow (isliye >= use kiya)
✔ Stack me sirf operators & brackets store hote hain
✔ Postfix me brackets nahi aate

------------------------------------------------------------
⏱️ Time Complexity:
👉 O(N)
(N = length of expression)

✔ Har character ek baar process hota hai

------------------------------------------------------------
💾 Space Complexity:
👉 O(N)

✔ Stack + output string

------------------------------------------------------------
🚀 Example:

Input:  a + b * (c ^ d - e)

Output: abcd^e-*+

------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            ans += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}
