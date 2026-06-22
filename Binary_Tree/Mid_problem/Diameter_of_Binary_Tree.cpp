// File: LC_543_Diameter_of_Binary_Tree.cpp

/*
Problem: Diameter of Binary Tree
Platform: LeetCode 543
https://leetcode.com/problems/diameter-of-binary-tree/

Intuition (Hinglish):
- Diameter = Longest path between any two nodes (in terms of edges).
- Kisi bhi node ko center maan lo.
- Agar diameter current node ke through pass karta hai:
      diameterThroughNode = leftHeight + rightHeight
- Har node par ye value calculate karke maximum maintain kar lenge.

Approach:
1. Recursive function subtree ki height return karega.
2. Left aur right subtree ki height nikalo.
3. Current node ke through diameter = leftHeight + rightHeight.
4. Global/reference diameter ko update karo.
5. Parent ko current node ki height return karo.

Why:
- Actual diameter tree me kahin bhi ho sakta hai.
- Hum har node ko potential center maan kar check kar rahe hain.
- Jis node par actual diameter pass karega, waha maximum value mil jayegi.

TC: O(N)
SC: O(H)

Key Learning:
- Tree DP Pattern:
  Child se information lo -> Current node par answer update karo -> Parent ko required value return karo.
*/

class Solution {
public:

    int height(TreeNode* root, int& diameter) {

        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};
