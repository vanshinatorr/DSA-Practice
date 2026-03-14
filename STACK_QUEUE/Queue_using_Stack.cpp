#include <stack>
using namespace std;

/*
========================================================
PROBLEM
Implement Queue using Stacks (LeetCode 232)
https://leetcode.com/problems/implement-queue-using-stacks/

Queue Rule:
FIFO (First In First Out)

Stack Rule:
LIFO (Last In First Out)

Goal:
Use stacks to simulate queue behavior.

========================================================
APPROACH

Use two stacks:

s1 → used for push operation
s2 → used for pop / peek operation

Steps:

1. push(x)
   - Simply push element into stack s1.

2. pop()
   - If s2 is empty:
        move all elements from s1 → s2
   - This reverses the order.
   - Now s2.top() becomes the queue front.
   - Remove and return s2.top().

3. peek()
   - Same logic as pop()
   - Only return s2.top() without removing.

4. empty()
   - Queue is empty only when both stacks are empty.

========================================================
EXAMPLE

Operations:
push(1)
push(2)
push(3)

Stack s1:
1 2 3

Transfer s1 → s2

Stack s2:
3 2 1

Queue order becomes:
1 2 3

pop()  → 1
peek() → 2

========================================================
TIME COMPLEXITY

push()  → O(1)
pop()   → O(1) amortized
peek()  → O(1) amortized
empty() → O(1)

========================================================
SPACE COMPLEXITY

O(n)
because stacks store all elements.

========================================================
KEY REVISION TRICK

s1 → push stack
s2 → pop stack

Transfer elements from s1 → s2
ONLY when s2 becomes empty.

This keeps operations efficient.
========================================================
*/

class MyQueue {
public:

    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
