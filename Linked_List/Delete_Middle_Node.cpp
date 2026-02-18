/*
===========================================================
Question : Delete the Middle Node of a Linked List
Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

===========================================================

-------------------------
🧠 APPROACH (Fast & Slow Pointer)
-------------------------

1. If list has 0 or 1 node:
      → Return NULL (middle deletion makes list empty)

2. Initialize:
      slow = head
      fast = head

3. Move fast two steps ahead initially:
      fast = head->next->next

4. Move slow by 1 step and fast by 2 steps
      until fast reaches end.

5. Slow will stop just before the middle node.

6. Store middle node → relink → delete.

--------------------------------
🎯 WHY THIS WORKS?
--------------------------------
Starting fast two steps ahead ensures:
- For odd length → exact middle removed
- For even length → second middle removed
(as required by LeetCode)

--------------------------------
⏱ TIME COMPLEXITY
--------------------------------
O(N)  → Single traversal

--------------------------------
📦 SPACE COMPLEXITY
--------------------------------
O(1)  → No extra space used

--------------------------------
⚠ EDGE CASES HANDLED
--------------------------------
✔ Empty list
✔ Single node list
✔ Even length list
✔ Odd length list

===========================================================
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Edge Case: 0 or 1 node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast two steps ahead
        fast = fast->next->next;

        // Move both pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return head;
    }
};
