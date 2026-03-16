/*

Platform: LeetCode
https://leetcode.com/problems/min-stack/
Difficulty: Medium



Approach:
We maintain two stacks:

1. st → stores all elements.
2. minst → stores the minimum elements.

Push:
Push the value into the main stack.
If the min stack is empty or the value is smaller or equal to the current minimum, push it into the min stack as well.

Pop:
If the element being popped equals the current minimum, pop from both stacks.

Top:
Return the top of the main stack.

getMin:
Return the top of the min stack which always stores the current minimum.

Time Complexity:
push   → O(1)
pop    → O(1)
top    → O(1)
getMin → O(1)

Space Complexity:
O(n)
*/

class MinStack {
public:

```
stack<int> st, minst;

MinStack() {
}

void push(int val) {
    st.push(val);

    if (minst.empty() || val <= minst.top()) {
        minst.push(val);
    }
}

void pop() {
    if (st.top() == minst.top()) {
        minst.pop();
    }
    st.pop();
}

int top() {
    return st.top();
}

int getMin() {
    return minst.top();
}
```

};
