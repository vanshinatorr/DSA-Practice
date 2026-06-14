/**
 * Problem:
 * LeetCode 102. Binary Tree Level Order Traversal
 *
 * Given the root of a binary tree, return the level order traversal
 * of its nodes' values. (i.e., from left to right, level by level).
 *
 * Approach:
 * - Use Breadth First Search (BFS).
 * - Store nodes in a queue.
 * - For each level:
 *      1. Get current queue size.
 *      2. Process exactly 'size' nodes.
 *      3. Store their values in a temporary vector.
 *      4. Push their left and right children into the queue.
 * - After finishing one level, push the level vector into the answer.
 *
 * Time Complexity:
 * O(N)
 * - Every node is visited exactly once.
 *
 * Space Complexity:
 * O(N)
 * - Queue may contain up to N nodes in the worst case.
 *
 * Common Mistakes:
 * 1. Returning -1 instead of an empty vector for nullptr root.
 * 2. Using q.push(root->val) instead of q.push(root).
 * 3. Writing TreeNode* as int.
 * 4. Forgetting ans.push_back(check->val).
 * 5. Using while(q != empty()) instead of while(!q.empty()).
 * 6. Pushing root repeatedly instead of pushing children.
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> finalans;

        if (root == nullptr)
            return finalans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> ans;

            for (int i = 0; i < size; i++) {

                TreeNode* check = q.front();
                q.pop();

                ans.push_back(check->val);

                if (check->left) {
                    q.push(check->left);
                }

                if (check->right) {
                    q.push(check->right);
                }
            }

            finalans.push_back(ans);
        }

        return finalans;
    }
};
