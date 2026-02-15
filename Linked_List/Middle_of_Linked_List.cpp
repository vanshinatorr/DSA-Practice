/*
===============================================================================
LeetCode Problem: 876. Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/description/
===============================================================================

Problem Statement:
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 3 -> 4 -> 5

Example 2:
Input:  1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 4 -> 5 -> 6

===============================================================================
Approach: Slow and Fast Pointer (Optimal Approach)
===============================================================================

We use two pointers:

1. slow pointer → moves one step at a time
2. fast pointer → moves two steps at a time

Why this works:
- fast pointer moves twice as fast as slow pointer
- when fast reaches the end, slow will be at the middle

This works for both odd and even length linked lists.
For even length, it automatically returns the second middle node.

===============================================================================
Algorithm Steps:
===============================================================================

1. Initialize:
   slow = head
   fast = head

2. Traverse the list until fast reaches end:
   while(fast != NULL && fast->next != NULL)
       slow = slow->next
       fast = fast->next->next

3. Return slow pointer (middle node)

===============================================================================
Complexity Analysis:
===============================================================================

Time Complexity: O(n)
Reason: We traverse the list only once.

Space Complexity: O(1)
Reason: No extra memory is used.

===============================================================================
Why this is Optimal:
===============================================================================

- Single traversal
- Constant space
- Interview preferred solution
- Better than brute force (counting method requires two traversals)

===============================================================================
Tags:
Linked List, Two Pointer, Slow Fast Pointer, Interview Favorite

===============================================================================
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        // initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // move slow by 1 step and fast by 2 steps
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow pointer will be at the middle node
        return slow;
    }
};
