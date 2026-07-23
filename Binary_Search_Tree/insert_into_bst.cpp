# 701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/description/


---

# Intuition

In a BST:

* If `val < root->val` → Move Left
* Otherwise → Move Right

Keep moving until you reach a `NULL` node.

Create the new node there.

---

# Approach 1 - Recursive

### Algorithm

1. If `root == nullptr`

   * Create and return a new node.
2. If `val < root->val`

   * Insert into the left subtree.
3. Otherwise

   * Insert into the right subtree.
4. Return the current root.

---

### Recursive Code

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
```

---

### Time Complexity

```
O(H)

Worst Case : O(N)
Average Case : O(log N)
```

### Space Complexity

```
O(H)

(Recursive call stack)
```

---

# Approach 2 - Iterative

### Algorithm

1. If the tree is empty, return a new node.
2. Start from the root.
3. Compare the value:

   * Move left if smaller.
   * Move right if greater.
4. When a `NULL` child is found, insert the new node.
5. Return the original root.

---

### Iterative Code

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == nullptr)
            return new TreeNode(val);

        TreeNode* curr = root;

        while (true) {

            if (val < curr->val) {

                if (curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    curr->left = new TreeNode(val);
                    break;
                }

            } else {

                if (curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    curr->right = new TreeNode(val);
                    break;
                }

            }
        }

        return root;
    }
};
```

---

### Time Complexity

```
O(H)

Worst Case : O(N)
Average Case : O(log N)
```

### Space Complexity

```
O(1)
```

---

* Recursive solution uses **O(H)** stack space, while the iterative solution uses **O(1)** extra space.
