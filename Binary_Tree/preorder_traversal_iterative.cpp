/**
 * Problem:
 * LeetCode 144 - Binary Tree Preorder Traversal
 *
 * Given the root of a binary tree, return its preorder traversal.
 *
 * Preorder Order:
 * Root -> Left -> Right
 *
 * Approach (Iterative - Stack):
 * 1. If tree is empty, return empty answer.
 * 2. Push root into stack.
 * 3. While stack is not empty:
 *      - Pop top node.
 *      - Store its value.
 *      - Push right child first.
 *      - Push left child second.
 * 4. Since stack is LIFO, left child gets processed before right child.
 *
 * Why push right before left?
 * Stack follows Last In First Out.
 *
 * Example:
 *      1
 *     / \
 *    2   3
 *
 * Push: 3 then 2
 *
 * Stack Top -> 2
 * Therefore traversal becomes:
 * 1 -> 2 -> 3
 *
 * Time Complexity:
 * O(n)
 *
 * Space Complexity:
 * O(h)
 * h = height of tree
 * Worst Case = O(n)
 *
 * Common Mistakes:
 * 1. Writing:
 *      if(root != nullptr) return ans;
 *    instead of:
 *      if(root == nullptr) return ans;
 *
 * 2. Pushing left before right.
 *    This produces incorrect preorder order.
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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* check = st.top();
            st.pop();

            ans.push_back(check->val);

            if (check->right) {
                st.push(check->right);
            }

            if (check->left) {
                st.push(check->left);
            }
        }

        return ans;
    }
};
