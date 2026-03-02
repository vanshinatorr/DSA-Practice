/*
Problem: LeetCode 25 - Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/

------------------------------------------------------------
Approach:
1. First, check if at least k nodes exist starting from current head.
   - Traverse k nodes using a temporary pointer.
   - If less than k nodes are available, return head as it is.

2. Reverse the first k nodes using standard linked list reversal logic.
   - Maintain three pointers:
       previous -> stores reversed part
       current  -> node being processed
       nextNode -> temporarily stores next node
   - Reverse exactly k nodes.

3. After reversing:
   - 'previous' becomes new head of this reversed group.
   - Original 'head' becomes the tail of this group.
   - Recursively call function for remaining list starting from 'current'.

4. Connect:
   - head->next = recursive result
   - Return 'previous' as new head.

------------------------------------------------------------
Time Complexity:
O(n)
Each node is visited exactly once.

Space Complexity:
O(n)
Due to recursion stack (worst case n/k recursive calls).

------------------------------------------------------------
Code:
------------------------------------------------------------
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check if at least k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return head;  // Not enough nodes
            }
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* previous = nullptr;
        ListNode* current = head;
        int count = k;

        while (count--) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        // Step 3: Recursively process remaining list
        head->next = reverseKGroup(current, k);

        return previous;  // New head of reversed group
    }
};
