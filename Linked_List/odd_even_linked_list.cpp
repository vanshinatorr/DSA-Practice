/*
===========================================================
https://leetcode.com/problems/odd-even-linked-list/
PROBLEM: Odd Even Linked List (LeetCode 328)
DIFFICULTY: Medium
===========================================================

DESCRIPTION:
Given the head of a singly linked list, group all odd-indexed
nodes together followed by the even-indexed nodes.

Indexing is 1-based:
1st node -> odd
2nd node -> even
3rd node -> odd
4th node -> even
...

Return the reordered linked list.

-----------------------------------------------------------
Example:

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 3 -> 5 -> 2 -> 4

===========================================================
APPROACH (Striver Standard Approach):

1. Maintain two pointers:
   - odd  -> head
   - even -> head->next
2. Store evenHead to attach later
3. Rearrange pointers inside loop
4. Connect odd list to evenHead at end

Loop condition:
while (even != nullptr && even->next != nullptr)

This ensures safe access to even->next->next

===========================================================
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
===========================================================
*/

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Edge Case
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Rearranging nodes
        while (even != nullptr && even->next != nullptr) {

            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        // Connect odd list with even list
        odd->next = evenHead;

        return head;
    }
};

/*
===========================================================
INTERVIEW NOTES:

- Loop controlled by even pointer
- Safe because we access even->next->next
- Odd pointer automatically safe since odd->next == even

Commonly Asked In:
Amazon, Microsoft, Adobe, Google

Related Problems:
- Reverse Linked List
- Palindrome Linked List
- Linked List Cycle
===========================================================
*/
