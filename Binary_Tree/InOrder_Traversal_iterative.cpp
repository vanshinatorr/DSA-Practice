/*
=========================================================
Problem: Binary Tree Inorder Traversal (Iterative)
Platform: LeetCode 94
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/2033610103/

Traversal Order:
Left -> Root -> Right

Approach:
- Use an explicit stack to simulate recursion.
- Keep moving left and push all nodes into the stack.
- When left becomes NULL:
    - Pop the top node.
    - Visit (store) its value.
    - Move to its right subtree.
- Repeat until both:
    - current node is NULL
    - stack becomes empty

Why while(node != NULL || !st.empty()) ?
- node != NULL :
    There are still nodes to explore on the current path.
- !st.empty() :
    There are parent nodes waiting to be processed.

Time Complexity:
O(N)

Space Complexity:
O(H)
H = Height of tree
Worst Case: O(N)
Balanced Tree: O(log N)

Key Learning:
- Stack stores ancestors while moving left.
- NULL acts as a signal that the left subtree is finished.
- After reaching NULL, we backtrack using the stack.
=========================================================
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* node = root;

        while (node != NULL || !st.empty()) {

            // Move completely to the left
            while (node != NULL) {
                st.push(node);
                node = node->left;
            }

            // Process current root
            node = st.top();
            st.pop();

            ans.push_back(node->val);

            // Explore right subtree
            node = node->right;
        }

        return ans;
    }
};
