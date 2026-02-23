/*
------------------------------------------------------------
Problem: Find All Pairs With Given Sum in Sorted DLL
Platform: Code360
Author: Vansh Vijay

Approach:
- Since the doubly linked list is sorted,
  we use the Two Pointer Technique.
- One pointer (left) starts from head.
- One pointer (right) starts from tail.
- If sum == k → store pair and move both.
- If sum < k → move left forward.
- If sum > k → move right backward.

Time Complexity: O(N)
    - We traverse the list once.

Space Complexity: O(1)
    - No extra data structure used
      (excluding result storage).

------------------------------------------------------------
*/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    if (head == nullptr) {
        return {};
    }

    vector<pair<int,int>> ans;

    Node* left = head;
    Node* right = head;

    // Move right pointer to the last node
    while (right->next != nullptr) {
        right = right->next;
    }

    // Two pointer traversal
    while (left->data < right->data) {

        int sum = left->data + right->data;

        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < k) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ans;
}
