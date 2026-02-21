/*
=========================================================
Sort Linked List of 0s, 1s and 2s
https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?interviewProblemRedirection=true&search=sort%20linked%20list%20&leftPanelTabValue=PROBLEM
on code 360
Approach: Three Dummy List Partitioning
Author: Vansh Vijay
=========================================================

🔹 Problem:
Given a linked list containing only 0s, 1s, and 2s,
sort the list without modifying node values.

---------------------------------------------------------
🔹 Approach:

1. Create three dummy nodes:
   - zeroHead → for nodes with data = 0
   - oneHead  → for nodes with data = 1
   - twoHead  → for nodes with data = 2

2. Traverse original list:
   - Attach each node to its respective list.
   - Move pointer forward.

3. Connect three lists:
   - 0-list → 1-list → 2-list

4. Return new head (zeroHead->next)

---------------------------------------------------------
🔹 Why This Approach?

- No data swapping.
- Stable ordering maintained.
- Single traversal.
- Clean pointer manipulation.

---------------------------------------------------------
🔹 Time Complexity:
O(n)
- Single traversal of linked list.

🔹 Space Complexity:
O(1)
- Only dummy nodes used.
- No extra data structure.

---------------------------------------------------------
🔹 Key Concepts:
- Dummy nodes simplify edge cases.
- Entire chains attached at once.
- Properly terminate last list with NULL.
=========================================================
*/


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/


Node* sortList(Node *head){

    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;

    // Dummy nodes for 0s, 1s and 2s
    Node* zerohead = new Node(-1);
    Node* onehead  = new Node(-1);
    Node* twohead  = new Node(-1);

    Node* zero = zerohead;
    Node* one  = onehead;
    Node* two  = twohead;

    Node* temp = head;

    // Traverse original list
    while (temp != nullptr){

        if (temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    // Connect the three lists

    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next  = (twohead->next) ? twohead->next : nullptr;
    two->next  = nullptr;

    Node* newhead = zerohead->next;

    // Free dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return newhead;
}
