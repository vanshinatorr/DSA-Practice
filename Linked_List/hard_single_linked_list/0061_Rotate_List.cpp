/*
============================================================
LeetCode 61 - Rotate List
File: 0061_Rotate_List.cpp
https://leetcode.com/problems/rotate-list/description/
============================================================

🔹 Problem:
Given the head of a linked list, rotate the list to the right by k places.

------------------------------------------------------------
🔹 Approach (Optimal - Circular Linked List Method)

1. Edge Case Handling:
   - If head is NULL OR k == 0 → return head directly.

2. Find Length of Linked List:
   - Traverse till last node.
   - Count total length (len).
   - Keep pointer at last node.

3. Optimize k:
   - k = k % len
   - If k == 0 → no rotation needed → return head.

4. Make List Circular:
   - Connect last node → head.

5. Find New Tail:
   - New tail will be at position (len - k).
   - Traverse (len - k - 1) steps from head.

6. Break the Circle:
   - newHead = tail->next
   - tail->next = NULL

7. Return newHead.

------------------------------------------------------------
🔹 Why This Works?
Instead of rotating one by one (which would be O(n*k)),
we:
- Calculate effective rotation using modulo
- Convert to circular list
- Break at correct position

This gives optimal performance.

------------------------------------------------------------
🔹 Time Complexity:
O(n)
- One traversal to calculate length
- One traversal to find new tail

------------------------------------------------------------
🔹 Space Complexity:
O(1)
- No extra space used

------------------------------------------------------------
🔹 Interview Revision Notes:
✔ Always reduce k using modulo.
✔ Converting to circular list simplifies rotation.
✔ Carefully calculate new tail position.
✔ Watch edge cases: empty list, single node, k multiple of len.

============================================================
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || k == 0) {
            return head; 
        }

        ListNode* temp = head; 
        int len = 1; 

        while (temp->next != nullptr) {
            temp = temp->next; 
            len++; 
        }

        k = k % len;
        if (k == 0) {
            return head; 
        }

        temp->next = head;  // Make circular list

        int steps = len - k; 
        ListNode* tail = head; 

        for (int i = 1; i < steps; i++) {
            tail = tail->next; 
        }

        ListNode* newHead = tail->next; 
        tail->next = nullptr; 

        return newHead; 
    }
};
