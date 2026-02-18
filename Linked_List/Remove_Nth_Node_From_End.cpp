/*
===========================================================
Question    : Remove Nth Node From End of List
Link        : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Difficulty  : Medium
Topic       : Linked List, Two Pointers
===========================================================

-------------------------
🧠 APPROACH (Two Pointer Technique)
-------------------------

1. Use two pointers: fast and slow.
2. Move fast pointer 'n' steps ahead.
3. If fast becomes NULL after moving n steps:
      → It means we have to delete the head node.
4. Otherwise:
      → Move both fast and slow together
      → Until fast reaches the last node.
5. Slow will now be just before the node to delete.
6. Store node to delete → relink → delete.

--------------------------------
🎯 WHY THIS WORKS?
--------------------------------
Maintains a gap of 'n' nodes between fast and slow.
When fast reaches end,
slow is exactly before nth node from end.

--------------------------------
⏱ TIME COMPLEXITY
--------------------------------
O(N)  → Single traversal of list

--------------------------------
📦 SPACE COMPLEXITY
--------------------------------
O(1)  → No extra space used

--------------------------------
⚠ EDGE CASES HANDLED
--------------------------------
✔ Empty list
✔ Single node list
✔ n == length (delete head)
✔ General case deletion

===========================================================
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Edge Case: Empty List
        if (head == nullptr)
            return nullptr;

        ListNode* fast = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast becomes NULL → delete head
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* slow = head;

        // Move both until fast reaches last node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete nth node from end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
