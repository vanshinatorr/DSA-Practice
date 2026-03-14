
/*
PROBLEM
Implement Stack using Queue (LeetCode 225)
https://leetcode.com/problems/implement-stack-using-queues/description/



IDEA
Stack → LIFO (Last In First Out)
Queue → FIFO (First In First Out)

To simulate stack using queue we use a rotation trick.

After inserting a new element into queue,
we rotate the previous elements behind it so that
the newest element moves to the front.

Example
push(1) → 1
push(2) → 2 1
push(3) → 3 2 1

So queue front always represents stack top.

------------------------------------------------

ALGORITHM

push(x)
1. Insert element into queue
2. Rotate previous elements (size-1 times)

Rotation trick
q.push(q.front())
q.pop()

This moves the front element to the back.

------------------------------------------------

EXAMPLE

push(1)
Queue → 1

push(2)
Queue → 2 1

push(3)
Queue → 3 2 1

pop() → 3
top() → 2

------------------------------------------------

TIME COMPLEXITY

push()  → O(n)
pop()   → O(1)
top()   → O(1)
empty() → O(1)

SPACE COMPLEXITY

O(n) because queue stores all elements.

------------------------------------------------

REVISION NOTE

Key trick:
Rotate queue after every push so the latest element
comes to the front and behaves like stack top.
*/

class MyStack {
public:

    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();

        for(int i = 1; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
