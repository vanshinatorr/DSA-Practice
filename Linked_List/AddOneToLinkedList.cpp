/*
===============================================================================
File Name   : AddOneToLinkedList.cpp
Author      : Your Name
Created On  : YYYY-MM-DD
Platform    : Coding Ninjas / Interview Prep
Topic       : Linked List
Problem     : Add One To Linked List
Difficulty  : Easy / Medium
===============================================================================

🧠 PROBLEM SUMMARY:
Given a non-negative integer represented as a singly linked list 
(MSD at head), add 1 to the number and return the updated list.

Example:
Input  : 1 -> 2 -> 9
Output : 1 -> 3 -> 0

-------------------------------------------------------------------------------

💡 APPROACH (Reverse Method - Optimal)

Step 1: Reverse the linked list.
        (So we can start addition from least significant digit.)

Step 2: Initialize carry = 1 (because we need to add 1).

Step 3: Traverse while carry == 1:
        - If digit == 9 → make it 0 (carry continues)
        - Else → add 1 and stop carry

Step 4: If carry still remains after full traversal (case like 9999),
        create a new node with value 1 and attach at the end 
        of reversed list.

Step 5: Reverse the list back to restore original order.

-------------------------------------------------------------------------------

⏱ TIME COMPLEXITY:
Reverse 1st time  : O(N)
Addition traversal: O(N)
Reverse 2nd time  : O(N)
Total             : O(N)

💾 SPACE COMPLEXITY:
O(1)  (No recursion, constant extra space)

-------------------------------------------------------------------------------

⚠ EDGE CASES HANDLED:
- 9999  → 10000
- 0     → 1
- Single node
- Multiple carry propagation
- Large input size

-------------------------------------------------------------------------------

🎯 WHY THIS IS OPTIMAL FOR INTERVIEWS:
✔ Iterative (No stack overflow risk)
✔ O(1) extra space
✔ Clean carry handling
✔ Industry friendly solution
✔ Handles all edge cases

===============================================================================
*/

ListNode* reverse(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}


ListNode* addOneToLinkedList(ListNode* head) {

    // Step 1: Reverse the linked list
    head = reverse(head);

    ListNode* temp = head;
    int carry = 1;

    // Step 2: Add 1 with carry handling
    while (temp != NULL && carry == 1) {

        if (temp->val == 9) {
            temp->val = 0;
            carry = 1;
        }
        else {
            temp->val = temp->val + 1;
            carry = 0;
        }

        temp = temp->next;
    }

    // Step 3: If carry still remains (e.g., 9999 case)
    if (carry == 1) {
        ListNode* newNode = new ListNode(1);

        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Step 4: Reverse back to original order
    head = reverse(head);

    return head;
}
