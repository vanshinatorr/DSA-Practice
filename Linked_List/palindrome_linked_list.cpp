/*
===========================================================
https://leetcode.com/problems/palindrome-linked-list/

PROBLEM: Palindrome Linked List (LeetCode 234)
DIFFICULTY: Easy
===========================================================

DESCRIPTION:
Given the head of a singly linked list, return true if it
is a palindrome, otherwise return false.

A palindrome reads the same forward and backward.

Example 1:
Input:  1 -> 2 -> 2 -> 1
Output: true

Example 2:
Input:  1 -> 2
Output: false

===========================================================
APPROACH:
1. Find the middle of the linked list using slow-fast pointers
2. Reverse the second half of the linked list
3. Compare first half and reversed second half
4. If all values match → palindrome

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

    // Reverse Linked List
    ListNode* Reverse(ListNode* head) {

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

    // Check Palindrome
    bool isPalindrome(ListNode* head) {

        // Edge case
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondhalf = Reverse(slow->next);

        // Step 3: Compare halves
        ListNode* firsthalf = head;

        while (secondhalf != nullptr) {

            if (firsthalf->val != secondhalf->val)
                return false;

            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }

        return true;
    }
};

/*
===========================================================
INTERVIEW NOTES:

Key concepts used:
- Fast and slow pointer
- Reverse linked list
- Two pointer comparison

Related problems:
- Reverse Linked List
- Middle of Linked List
- Linked List Cycle
===========================================================
*/
