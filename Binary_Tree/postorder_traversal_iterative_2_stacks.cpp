/**
 * LeetCode 145 - Binary Tree Postorder Traversal
 *  Link : https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/2034309657/
 * Approach:
 * Iterative Postorder Traversal using Two Stacks
 *
 * Postorder Order:
 * Left -> Right -> Root
 *
 * Idea:
 * 1. Push root into st1.
 * 2. Pop node from st1 and push it into st2.
 * 3. Push its left child into st1.
 * 4. Push its right child into st1.
 * 5. Continue until st1 becomes empty.
 * 6. Pop all nodes from st2.
 *
 * Why does it work?
 * ------------------
 * st2 stores nodes in:
 * Root -> Right -> Left
 *
 * When we pop from st2, the order gets reversed:
 * Left -> Right -> Root
 *
 * which is exactly Postorder Traversal.
 *
 * Why Two Stacks?
 * ---------------
 * I intentionally used the 2-stack approach instead of the
 * optimized 1-stack approach.
 *
 * Reason:
 * - Easier to understand.
 * - Easier to explain in interviews.
 * - Lower chance of bugs.
 * - Directly follows the reverse-preorder concept.
 *
 * The 1-stack solution is more space optimized but involves
 * additional pointer tracking and is comparatively trickier.
 *
 * For placement interviews, being able to confidently derive
 * and explain the 2-stack approach is usually more valuable
 * than memorizing the optimized version.
 *
 * Time Complexity:
 * O(N)
 *
 * Space Complexity:
 * O(N)
 *
 * Common Mistake:
 * Forgetting st1.pop() after accessing st1.top(),
 * which causes an infinite loop.
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> postorder;

        if (root == nullptr) {
            return postorder;
        }

        stack<TreeNode*> st1, st2;

        st1.push(root);

        while (!st1.empty()) {

            TreeNode* curr = st1.top();
            st1.pop();

            st2.push(curr);

            if (curr->left != nullptr) {
                st1.push(curr->left);
            }

            if (curr->right != nullptr) {
                st1.push(curr->right);
            }
        }

        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
