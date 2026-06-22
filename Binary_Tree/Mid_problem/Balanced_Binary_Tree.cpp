/*
=========================================================
Problem: Balanced Binary Tree
Platform: LeetCode 110
Link: https://leetcode.com/problems/balanced-binary-tree/

Intuition:
- Hume har node par check karna hai ki left aur right subtree
  ki height ka difference 1 se zyada na ho.
- Agar har node ye condition satisfy karti hai to tree balanced hai.
- Brute force approach me har node ke liye baar-baar height
  calculate karni padti hai, jiski wajah se complexity O(N²)
  ho sakti hai.
- Isliye height calculate karte waqt hi balance bhi check karenge.
- Agar kisi subtree me imbalance mil jaye to -1 return kar denge.
- Ye -1 ek special signal ki tarah kaam karega aur recursion me
  upar tak propagate ho jayega.

Approach:
- Use Postorder Traversal (Left -> Right -> Root).
- First calculate left subtree height.
- Then calculate right subtree height.
- If any subtree returns -1:
      return -1.
- If abs(leftHeight - rightHeight) > 1:
      return -1.
- Otherwise return:
      1 + max(leftHeight, rightHeight)

Why return -1 ?
- Height kabhi negative nahi hoti.
- Isliye -1 ko safely "Unbalanced Subtree" ka flag bana sakte hain.
- Ek baar -1 mil gaya to remaining recursion ko direct signal
  mil jata hai ki tree balanced nahi hai.

Time Complexity:
O(N)

Space Complexity:
O(H)

H = Height of Tree
Balanced Tree : O(log N)
Worst Case    : O(N)

Key Learning:
- Height calculation aur balance checking ko ek hi DFS me
  combine kar sakte hain.
- Postorder traversal use hota hai kyunki current node ka answer
  children ki heights par depend karta hai.
- -1 ko flag ki tarah use karke O(N²) brute force ko O(N)
  me optimize kar sakte hain.
=========================================================
*/

class Solution {
public:
    int height(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);

        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = height(root->right);

        if (rightHeight == -1) {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
```
