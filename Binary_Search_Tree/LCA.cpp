# 235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/2081963743/


**Platform:** LeetCode
**Difficulty:** Medium

---

# Intuition

Use the **BST property**.

* If both `p` and `q` are smaller than the current node, move to the **left subtree**.
* If both `p` and `q` are greater than the current node, move to the **right subtree**.
* Otherwise, the current node is the **Lowest Common Ancestor (LCA)**.

---

# Approach

1. If the tree is empty, return `nullptr`.
2. If both nodes are in the left subtree, recurse left.
3. If both nodes are in the right subtree, recurse right.
4. Otherwise, return the current node because it is the first node where the paths split (or one node is the current root).

---

# Why This Works

In a Binary Search Tree:

* Left subtree contains smaller values.
* Right subtree contains larger values.

As long as both nodes are on the same side, continue moving in that direction.

The first node where they are on different sides (or one of them is the current node) is the **Lowest Common Ancestor**.

---

# Time Complexity

**O(H)**

* `H` = Height of the BST.
* We visit only one node per level.

---

# Space Complexity

**O(H)** (Recursive call stack)

* Balanced BST: **O(log N)**
* Skewed BST: **O(N)**

---

# Code (C++)

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
```

---

# Key Learning

* Use the **BST property** instead of traversing the entire tree.
* Only **two conditions** are needed:

  * Both nodes are in the left subtree.
  * Both nodes are in the right subtree.
* All remaining cases are handled by `return root`:

  * One node is on the left and the other is on the right.
  * `p` is the current root.
  * `q` is the current root.

### Golden Rule

> **Both Left → Go Left**
> **Both Right → Go Right**
> **Otherwise → Current Root is the LCA**
