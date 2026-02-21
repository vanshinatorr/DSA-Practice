/*
=========================================================
LeetCode 148 - Sort List
Approach: Merge Sort on Linked List
Author: Vansh Vijay
=========================================================

🔹 Problem:
Sort a linked list in O(n log n) time and constant space complexity.

---------------------------------------------------------
🔹 Approach (Merge Sort on Linked List):

1. Base Case:
   - If list is empty or has only one node → already sorted.

2. Divide:
   - Use slow & fast pointer to find middle.
   - Split list into two halves.

3. Conquer:
   - Recursively sort left half.
   - Recursively sort right half.

4. Combine:
   - Merge two sorted linked lists.

---------------------------------------------------------
🔹 Why Merge Sort for Linked List?

- Linked list does NOT allow random access.
- Quick sort is inefficient for linked lists.
- Merge sort works naturally by pointer manipulation.

---------------------------------------------------------
🔹 Time Complexity:
O(n log n)
- Each level splits list into halves (log n levels)
- Each merge takes O(n)

🔹 Space Complexity:
O(log n)
- Due to recursion stack
- No extra array used

---------------------------------------------------------
🔹 Key Concepts:
- Fast pointer starts from head->next for balanced split
- temp pointer moves forward after attaching node
- Remaining list attached in one step
=========================================================
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    // 🔹 Find Middle using Slow-Fast Pointer
    ListNode* findmiddle(ListNode* head){

        ListNode* slow = head;  
        ListNode* fast = head;
        fast = head->next;   // start fast from next for balanced split

        while (fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next; 
        }

        return slow; 
    }


    // 🔹 Merge Two Sorted Linked Lists
    ListNode* mergeTwoLists(ListNode* l1 , ListNode* l2){

        ListNode* dummyNode = new ListNode(-1);   // dummy starting node
        ListNode* temp = dummyNode; 

        while (l1 != 0 && l2 != 0){

            if (l1->val < l2->val){
                temp->next = l1; 
                l1 = l1->next; 
            }
            else{
                temp->next = l2; 
                l2 = l2->next; 
            }

            temp = temp->next;   // move temp forward
        }

        // attach remaining nodes (entire chain at once)
        if (l1 != 0){
            temp->next = l1;
        }
        else{
            temp->next = l2; 
        }

        return dummyNode->next; 
    }


    // 🔹 Main Merge Sort Function
    ListNode* sortList(ListNode* head){

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head; 

        // Step 1: Divide
        ListNode* middle = findmiddle(head);

        ListNode* right = middle->next; 
        middle->next = NULL; 
        ListNode* left = head;  

        // Step 2: Conquer
        left = sortList(left);
        right = sortList(right);

        // Step 3: Combine
        return mergeTwoLists(left, right); 
    }
};
