# Right Side View of Binary Tree (LeetCode 199)

**Platform:** LeetCode
  
https://leetcode.com/problems/binary-tree-right-side-view/submissions/2056946536/
---

## Intuition (Hinglish)

Har level par **sirf wahi node dikhai degi jo sabse right me hogi**.

DFS use karte hain aur **Right → Left** order me traverse karte hain.

Jab kisi level par **pehli baar** pahunchte hain, to wahi us level ki rightmost node hogi, kyunki hum pehle right subtree visit kar rahe hain.

Isliye agar:

```cpp
rightView.size() == level
```

to us node ko answer me add kar dete hain.

---

## Approach

1. Base case: Agar node `nullptr` hai to return.
2. Agar current level pe pehli baar aaye hain (`rightView.size() == level`), node ko answer me push karo.
3. Pehle **right subtree** traverse karo.
4. Fir **left subtree** traverse karo.

---


## Complexity

* **Time:** `O(N)` (Har node ek hi baar visit hoti hai.)
* **Space:** `O(H)` (Recursion stack, `H` = tree height. Worst case `O(N)`, balanced tree `O(log N)`.)

---

## Code

```cpp
class Solution {
public:

    void getRightView(TreeNode* root, vector<int>& rightView, int level) {

        if (root == nullptr) {
            return;
        }

        if (rightView.size() == level) {
            rightView.push_back(root->val);
        }

        getRightView(root->right, rightView, level + 1);
        getRightView(root->left, rightView, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> rightView;

        getRightView(root, rightView, 0);

        return rightView;
    }
};
```

---

## Key Learning

* Tree ke **views (Left View / Right View)** ko DFS se bhi solve kar sakte hain.
* **Right View:** `Right → Left` traversal.
* **Left View:** `Left → Right` traversal.
* `answer.size() == level` ka matlab hai **is level ki first visited node**, aur traversal order decide karta hai ki woh leftmost hogi ya rightmost.
