/*
========================================================
https://leetcode.com/problems/add-two-numbers/submissions/1927597687/

Problem: Add Two Numbers (Linked List)
Platform: LeetCode
Time Complexity: O(max(N, M))
Space Complexity: O(max(N, M))
========================================================

APPROACH:

1. Create a dummy node to simplify list construction.
2. Use a pointer (temp) to build the result list.
3. Maintain a carry variable (like normal addition).
4. Traverse both lists simultaneously:
      sum = carry
      add l1 value if exists
      add l2 value if exists
      create new node with (sum % 10)
      update carry = sum / 10
5. Continue until l1, l2 and carry are all finished.
6. Return dummy->next (actual head of result list).

WHY DUMMY NODE?
- Avoids checking if head is NULL.
- Makes insertion logic simple.
- Removes special case for first node.

TIME COMPLEXITY:
O(max(N, M))
N = length of l1
M = length of l2
We traverse both lists once.

SPACE COMPLEXITY:
O(max(N, M))
Because we create a new result list.

========================================================
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Step 1: Create dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        int carry = 0;  // Step 2: Initialize carry
        
        // Step 3: Traverse both lists
        while (l1 != NULL || l2 != NULL || carry != 0) {
            
            int sum = carry;  // Start with previous carry
            
            // Add value from l1 if available
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add value from l2 if available
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Update carry
            carry = sum / 10;
            
            // Create new node with last digit
            ListNode* newNode = new ListNode(sum % 10);
            
            // Attach to result list
            temp->next = newNode;
            temp = temp->next;
        }
        
        // Step 4: Return actual result (skip dummy)
        return dummy->next;
    }
};
