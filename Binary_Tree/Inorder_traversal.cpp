/*
=========================================================
Problem: Binary Tree Inorder Traversal
Platform: LeetCode 94
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

Approach:
1. Inorder follows:
      Left -> Root -> Right

2. For every node:
      - Traverse left subtree
      - Visit current node
      - Traverse right subtree

3. Store visited nodes in a vector.

Time Complexity:
O(N)

Space Complexity:
O(H)
H = Height of Tree (Recursion Stack)

Key Learning:
- Base condition: root == NULL
- Same answer vector is passed by reference (&)
- Inorder means process node BETWEEN left and right recursive calls

Common Mistakes:
1. Forgetting base condition.
2. Passing vector without '&' causing copies.
3. Writing Root -> Left -> Right (Preorder by mistake).
4. Writing Left -> Right -> Root (Postorder by mistake).
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

    void inorder(vector<int>& ans, TreeNode* root) {

        if (root == NULL) {
            return;
        }

        // Left
        inorder(ans, root->left);

        // Root
        ans.push_back(root->val);

        // Right
        inorder(ans, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        inorder(ans, root);

        return ans;
    }
};
