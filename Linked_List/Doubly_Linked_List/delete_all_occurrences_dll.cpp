/*
------------------------------------------------------------
Problem: Delete All Occurrences of a Key in Doubly Linked List
https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM
Author: Vansh Vijay
------------------------------------------------------------

Approach:
1. Traverse the doubly linked list using a pointer `temp`.
2. For every node:
   - If temp->data == k:
        a) Store next and prev pointers.
        b) If deleting head → move head to next node.
        c) Fix previous node's next pointer.
        d) Fix next node's prev pointer.
        e) Delete the current node.
        f) Move temp to next node safely.
   - Else:
        Move temp forward.
3. Return updated head.

Key Concept:
Always store the next pointer before deleting a node 
to avoid accessing freed memory (use-after-delete error).

Time Complexity: O(N)
- We traverse the list once.

Space Complexity: O(1)
- No extra data structures used.
------------------------------------------------------------
*/

Node* deleteAllOccurrences(Node* head, int k) {

    Node* temp = head;

    while (temp != nullptr) {

        Node* frontNode = temp->next;
        Node* prevNode = temp->prev;

        if (temp->data == k) {

            // If deleting head
            if (temp == head) {
                head = frontNode;
                if (head != nullptr)
                    head->prev = nullptr;
            }

            // Fix previous link
            if (prevNode != nullptr) {
                prevNode->next = frontNode;
            }

            // Fix next link
            if (frontNode != nullptr) {
                frontNode->prev = prevNode;
            }

            delete temp;
            temp = frontNode;
        }
        else {
            temp = temp->next;
        }
    }

    return head;
}
