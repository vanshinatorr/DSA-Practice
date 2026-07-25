// # **98. Validate Binary Search Tree (LeetCode)**

// **Platform:** LeetCode
// **Difficulty:** Medium

// ---

// ## 🧠 Intuition (Hinglish)

// Har node ke liye ek **valid range (min, max)** maintain karte hain.

// * Root → `(-∞, +∞)`
// * Left → `(min, root->val)`
// * Right → `(root->val, max)`

// Agar node apni range ke bahar ho, to BST invalid hai.

// ---

// ## 🚀 Approach

// 1. `root == nullptr` → `true`
// 2. Agar `root->val <= min || root->val >= max` → `false`
// 3. Left subtree check with `(min, root->val)`
// 4. Right subtree check with `(root->val, max)`
// 5. Return `left && right`

// ---

// ## ⚠️ Key Mistakes

// * Parent se compare karna enough nahi hota, **range maintain karni padti hai**.
// * Har recursive call me `INT_MIN/INT_MAX` pass nahi karna, current `min/max` pass karna hai.
// * `int` ki jagah `long long` + `LLONG_MIN/LLONG_MAX` use karo (edge case: `INT_MIN`, `INT_MAX`).
// * Recursive calls ka result return/combine karna hota hai.

// ---

// ## ⏱ Complexity

// * **Time:** `O(n)`
// * **Space:** `O(h)` (Recursion Stack)

// ---


```cpp
class Solution {
public:
    bool checkvalid(TreeNode* root, long long min, long long max) {

        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return checkvalid(root->left, min, root->val) &&
               checkvalid(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return checkvalid(root, LLONG_MIN, LLONG_MAX);
    }
};
```

---

