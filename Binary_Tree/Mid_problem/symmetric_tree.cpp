## Problem Name
  link : https://leetcode.com/problems/symmetric-tree/
**Symmetric Tree (LeetCode 101)**

### Intuition

A symmetric tree is a **mirror image** of itself.

* `left->left` ↔ `right->right`
* `left->right` ↔ `right->left`

Use a helper function to compare two nodes recursively.

---

### Approach

1. If both nodes are `nullptr`, return `true`.
2. If one node is `nullptr`, return `false`.
3. If values are different, return `false`.
4. Recursively compare outer and inner children.
5. Return `true` if both comparisons are `true`.

---

### Time Complexity

**O(n)**

### Space Complexity

**O(h)**

---

### Code

```cpp
class Solution {
public:

    bool checkMirror(TreeNode* left, TreeNode* right) {

        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return checkMirror(left->left, right->right) &&
               checkMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return checkMirror(root->left, root->right);
    }
};
```

---

### Key Learning

* Symmetric Tree = **Mirror Tree**
* Compare **Outside ↔ Outside** and **Inside ↔ Inside**
* Use a helper function when comparing **two nodes recursively**.
