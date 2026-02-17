/*
===========================================================
PROBLEM: Find Length of Loop in Linked List
PLATFORM: Code360 

https://www.naukri.com/code360/problems/find-length-of-loop_8160455?utm_source=chatgpt.com&leftPanelTabValue=SUBMISSION
===========================================================

DESCRIPTION:
Given the head of a singly linked list, determine whether
a cycle exists. If a cycle exists, return the length of
the loop. Otherwise, return 0.

EXAMPLE:

Input:
4 -> 10 -> 3 -> 5 -> 10 (cycle back to 10)

Output:
3

Explanation:
Loop contains nodes: 10 -> 3 -> 5
Length = 3

===========================================================
APPROACH: Floyd’s Cycle Detection Algorithm

Step 1: Use slow and fast pointers to detect cycle
Step 2: If slow == fast, cycle exists
Step 3: Traverse loop once and count nodes
Step 4: Return count

===========================================================
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
===========================================================
*/

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

    int lengthOfLoop(Node *head) {

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Step 2: Cycle detected
            if (slow == fast) {

                // Step 3: Count loop length
                int count = 1;
                Node* temp = slow->next;

                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        // Step 4: No cycle
        return 0;
    }
};

/*
===========================================================
NOTES FOR INTERVIEW:

1. Uses Floyd’s Algorithm (Tortoise and Hare)
2. Optimal solution
3. No extra space used
4. Common FAANG interview question

RELATED QUESTIONS:
- Detect Cycle in Linked List
- Find Start of Cycle
- Remove Cycle
===========================================================
*/
