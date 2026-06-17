/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base Case
        if (root == nullptr)
            return 0;

        // Find depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Find depth of right subtree
        int rightDepth = maxDepth(root->right);

        // Current node depth
        return 1 + max(leftDepth, rightDepth);
    }
};
