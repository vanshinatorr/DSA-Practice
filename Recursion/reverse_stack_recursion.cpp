
/*
===========================================================
🧠 Problem: Reverse a Stack using Recursion
https://www.geeksforgeeks.org/problems/reverse-a-stack/1 
solved on gfg
===========================================================

Given a stack, reverse it using recursion only.
You are NOT allowed to use any extra data structures.

-----------------------------------------------------------
🎯 Approach:
-----------------------------------------------------------
1. Pop the top element (x)
2. Recursively reverse the remaining stack
3. Insert x at the bottom using helper function

We use TWO recursive functions:
- reverseStack() → empties the stack
- insertAtBottom() → inserts element at bottom

-----------------------------------------------------------
🔁 Key Insight:
-----------------------------------------------------------
Recursion works in TWO phases:
1. Forward phase → stack becomes empty
2. Backtracking → elements are inserted at bottom

-----------------------------------------------------------
⏱ Time Complexity:
-----------------------------------------------------------
O(N^2)
- Each insertAtBottom takes O(N)
- Called N times

-----------------------------------------------------------
📦 Space Complexity:
-----------------------------------------------------------
O(N) (recursion stack)

-----------------------------------------------------------
⚠️ Common Mistakes:
-----------------------------------------------------------
1. Passing stack by value instead of reference ❌
2. Forgetting base case in insertAtBottom ❌
3. Calling insert with wrong variable (temp instead of x) ❌

-----------------------------------------------------------
✅ Correct Implementation:
-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔽 Helper: Insert element at bottom of stack
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    // 🔽 Main function: Reverse stack
    void reverseStack(stack<int> &st) {
        if (st.empty()) return;

        int x = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, x);
    }
};

/*
-----------------------------------------------------------
🧪 Example:
-----------------------------------------------------------
Input Stack (top → bottom): 4 3 2 1

Process:
- Pop all elements → []
- Insert at bottom during backtracking

Output Stack (top → bottom): 1 2 3 4

-----------------------------------------------------------
💡 Interview Tip:
-----------------------------------------------------------
If asked:
"Why two functions?"

Answer:
- Separation of concerns
- One handles reversal logic
- One handles insertion logic

-----------------------------------------------------------
🚀 Practice Variations:
-----------------------------------------------------------
1. Reverse a Queue using recursion
2. Sort a Stack using recursion
3. Insert at kth position in stack

===========================================================
*/
```
