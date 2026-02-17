/*
===========================================================
PROBLEM: Linked List Cycle Detection
https://leetcode.com/problems/linked-list-cycle/submissions/1922131428/
===========================================================

Given the head of a singly linked list, determine if the
linked list has a cycle in it.

A cycle exists if some node in the list can be reached
again by continuously following the next pointer.

Return true if there is a cycle, otherwise return false.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
         ↑         ↓
         ← ← ← ← ← ←

Output:
true

===========================================================
APPROACH: Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
===========================================================

We use two pointers:

slow pointer -> moves 1 step at a time
fast pointer -> moves 2 steps at a time

Logic:
- If there is no cycle, fast will reach NULL
- If there is a cycle, fast and slow will meet

Why it works:
Fast pointer moves faster and eventually catches slow pointer
inside the cycle.

===========================================================
TIME COMPLEXITY: O(N)
- Each node is visited at most once

SPACE COMPLEXITY: O(1)
- No extra space used

===========================================================
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;

            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

};
