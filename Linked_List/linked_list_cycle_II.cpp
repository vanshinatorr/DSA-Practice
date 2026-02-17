/*
===========================================================
FILE: linked_list_cycle_II.cpp
PROBLEM: Linked List Cycle II (LeetCode 142)

https://leetcode.com/problems/linked-list-cycle-ii/
===========================================================

DESCRIPTION:
Given the head of a singly linked list, return the node
where the cycle begins. If there is no cycle, return NULL.

If a cycle exists, some node in the list points back to a
previous node, forming a loop.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
         ↑         ↓
         ← ← ← ← ← ←

Output:
Node with value 3

===========================================================
APPROACH: Floyd’s Cycle Detection Algorithm
===========================================================

Phase 1: Detect cycle
- Use slow and fast pointers
- slow moves 1 step
- fast moves 2 steps
- If they meet, cycle exists

Phase 2: Find cycle start
- Move slow to head
- Move both slow and fast one step at a time
- The node where they meet is the cycle start

===========================================================
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
===========================================================
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {

                // Phase 2: Find cycle start
                slow = head;

                while (slow != fast) {

                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle
        return nullptr;
    }

};
