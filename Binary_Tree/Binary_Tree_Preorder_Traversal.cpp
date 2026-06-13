/*
=========================================================
Problem: Binary Tree Preorder Traversal
Platform: LeetCode 144
https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/2031425130/

Approach:
1. Preorder follows:
      Root -> Left -> Right

2. For every node:
      - Visit current node
      - Traverse left subtree
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
- Preorder means process node BEFORE recursive calls

Common Mistakes:
1. Forgetting base condition.
2. Passing vector without '&' causing copies.
3. Writing Left -> Root -> Right (Inorder by mistake).
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

    void preorder(TreeNode* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }

        // Root
        ans.push_back(root->val);

        // Left
        preorder(root->left, ans);

        // Right
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};
