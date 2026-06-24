// File: LC_124_Binary_Tree_Maximum_Path_Sum.cpp

/*

LinK : https://leetcode.com/problems/binary-tree-maximum-path-sum/

Problem:
LeetCode 124 - Binary Tree Maximum Path Sum

Interview Approach (30 sec):

Har node par 2 cheeze calculate karni hain:

1. Parent ko kya return karna hai?
   - Parent ke path me sirf ek branch ja sakti hai.
   - return = root->val + max(left, right)

2. Current node ko center maan kar maximum path kya ban sakta hai?
   - candidate = left + right + root->val
   - isi se global answer (maxi) update karte hain.

Negative contributions ko ignore karne ke liye:
left = max(0, left)
right = max(0, right)

Postorder DFS use karenge kyunki current node ko process karne se pehle
left aur right subtree ka contribution chahiye.

Intuition (Hinglish):

return value != final answer

return:
- Parent ko maximum contribution.

maxi:
- Entire tree ka maximum path sum.

At every node:
candidate = left + right + root->val
maxi = max(maxi, candidate)

return root->val + max(left, right)

Why max(0, ...) ?

Agar koi subtree negative contribution de rahi hai,
to use path me include karne se answer aur chhota hoga.

TC: O(N)
SC: O(H)

Key Learning:
1. Global answer aur recursive return value alag cheeze ho sakti hain.
2. Parent ko sirf ek branch return hoti hai.
3. Answer update karte waqt dono branches use kar sakte hain.
4. Diameter of Binary Tree aur Maximum Path Sum ka pattern similar hai.
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

    int height(TreeNode* root, int &maxi) {

        if (root == nullptr)
            return 0;

        int left = max(0, height(root->left, maxi));
        int right = max(0, height(root->right, maxi));

        maxi = max(maxi, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        height(root, maxi);

        return maxi;
    }
};
