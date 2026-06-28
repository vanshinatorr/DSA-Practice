# LeetCode 100 - Same Tree

## Approach
- Compare both trees recursively.
- If both nodes are `NULL`, they are the same.
- If one node is `NULL` and the other is not, they are different.
- If both nodes exist but their values are different, return `false`.
- Recursively compare the left subtree and the right subtree.
- Return `true` only if both left and right subtrees are the same.

## Code 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case 1: Both nodes are NULL
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base Case 2: One node is NULL
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Base Case 3: Values are different
        if (p->val != q->val) {
            return false;
        }

        // Compare left subtree
        bool left = isSameTree(p->left, q->left);

        // Compare right subtree
        bool right = isSameTree(p->right, q->right);

        // Return true only if both are true
        if (left && right) {
            return true;
        }

        return false;
    }
};
```

## Time Complexity
- **O(n)**
- Every node is visited exactly once.

## Space Complexity
- **O(h)**
- `h` = height of the tree (recursive stack).
- Worst Case: **O(n)** (Skewed Tree)
- Best/Average Case: **O(log n)** (Balanced Tree)

## Key Learning
- Always write **base cases first**.
- The order of base cases matters.
- Never return `true` immediately after values match.
- Compare both left and right subtrees recursively before returning the final answer.
