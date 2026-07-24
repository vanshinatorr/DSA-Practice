
# 230. Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/2079488973/
**Platform:** LeetCode

### Intuition

* BST ka inorder traversal sorted order deta hai.
* Inorder karte hue `count` maintain karenge.
* Jab `count == k` hoga, wahi answer hoga.

### Approach

1. Left traverse.
2. `count++`
3. `count == k` ⇒ answer store.
4. Right traverse.

### Complexity

* **Time:** `O(n)`
* **Space:** `O(h)`



```cpp
class Solution {
public:
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* root, int k) {
        if (root == nullptr)
            return;

        inorder(root->left, k);

        count++;

        if (count == k)
            ans = root->val;

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        ans = 0;

        inorder(root, k);

        return ans;
    }
}
```

---
