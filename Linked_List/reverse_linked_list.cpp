/*
===========================================================
PROBLEM: Reverse a Singly Linked List
https://leetcode.com/problems/reverse-linked-list/ 
===========================================================

Given the head of a singly linked list, reverse the list,
and return the new head.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

===========================================================
APPROACH 1: ITERATIVE APPROACH (3 Pointer Method)
===========================================================

Logic:
We maintain three pointers:

prev  -> points to previous node
temp  -> points to current node
front -> stores next node

Steps:
1. Store next node in front
2. Reverse current node link
3. Move prev and temp forward

Time Complexity: O(N)
Space Complexity: O(1)

===========================================================
APPROACH 2: RECURSIVE APPROACH
===========================================================

Logic:
1. Reverse rest of list
2. Fix current node

Example:
1 -> 2 -> 3 -> NULL

reverse(2->3)
3 -> 2

attach 1 at end

Time Complexity: O(N)
Space Complexity: O(N)  (recursion stack)

===========================================================
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    /*
    ===========================================================
    ITERATIVE APPROACH
    ===========================================================
    */
    ListNode* reverseListIterative(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {

            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }

        return prev;
    }


    /*
    ===========================================================
    RECURSIVE APPROACH
    ===========================================================
    */
    ListNode* reverseListRecursive(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseListRecursive(head->next);

        ListNode* front = head->next;

        front->next = head;

        head->next = nullptr;

        return newHead;
    }

};
