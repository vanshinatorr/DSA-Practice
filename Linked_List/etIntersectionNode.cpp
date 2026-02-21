/*
===========================================================
https://leetcode.com/problems/intersection-of-two-linked-lists/
Author      : Vansh Vijay
Problem     : Intersection of Two Linked Lists
Platform    : LeetCode
===========================================================

Approach:
- Use two pointers (temp1, temp2).
- Start temp1 from headA and temp2 from headB.
- Traverse both lists simultaneously.
- When a pointer reaches NULL, redirect it to the head of the other list.
- If intersection exists, both pointers will meet at the intersection node.
- If no intersection, both will eventually become NULL.

Why This Works:
Each pointer travels lengthA + lengthB distance.
So they align automatically without calculating lengths.

Time Complexity  : O(m + n)
Space Complexity : O(1)

===========================================================
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != temp2){
            
            if(temp1 == NULL) temp1 = headB;
            else temp1 = temp1->next;
            
            if(temp2 == NULL) temp2 = headA;
            else temp2 = temp2->next;
        }
        
        return temp1;
    }
};
