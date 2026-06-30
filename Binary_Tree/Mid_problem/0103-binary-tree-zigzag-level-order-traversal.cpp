# 📄 File Name: `0103-binary-tree-zigzag-level-order-traversal.md`

# Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

**Platform:** LeetCode
**Problem No.:** 103
**Difficulty:** Medium

---

## 🧠 Intuition (Hinglish)

* Ye question **Level Order Traversal (BFS)** ka extension hai.
* Normal Level Order me har level **Left → Right** print hota hai.
* Is question me alternate levels ko **Right → Left** print karna hai.
* Isliye har level ko normal BFS se traverse karenge aur us level ki values ek vector me store karenge.
* Agar current direction **Right → Left** hai (`flag == 1`), to us vector ko `reverse()` kar denge.
* Queue ka order kabhi change nahi hota. Zigzag sirf output me aata hai.

---

## 🚀 Approach

1. Agar `root == nullptr` ho to empty vector return kar do.
2. Queue banao aur root ko push karo.
3. `flag = 0` rakho.

   * `0` → Left to Right
   * `1` → Right to Left
4. Jab tak queue empty na ho:

   * Current level ka size nikalo.
   * Us level ke saare nodes process karo.
   * Node ki value `level` vector me store karo.
   * Left aur Right child ko queue me push karo.
5. Agar `flag == 1` ho to `level` ko reverse karo.
6. `level` ko final answer me push kar do.
7. Flag ko toggle karo.
8. Final answer return kar do.

---

## ❓ Why?

* Queue hamesha children ko **Left → Right** order me hi store karti hai.

```cpp
if (node->left)
    q.push(node->left);

if (node->right)
    q.push(node->right);
```

* Agar queue ka order change karenge to next level ka traversal hi change ho jayega.
* Isliye queue ko same rakhte hain aur sirf current level ke output ko reverse kar dete hain.

---

## ⏱️ Time Complexity

* BFS Traversal → **O(N)**
* Reverse of all levels combined → **O(N)**

**Overall:** `O(N)`

---

## 💾 Space Complexity

* Queue → **O(N)**
* Answer Vector → **O(N)**

**Overall:** `O(N)`

---

## ⚠️ Common Mistakes

* `root == nullptr` handle karna mat bhoolna.

```cpp
if (root == nullptr)
    return {};
```

* `pop()` value return nahi karta.

❌ Wrong

```cpp
TreeNode* node = q.pop();
```

✅ Correct

```cpp
TreeNode* node = q.front();
q.pop();
```

* Queue me `TreeNode*` store karna hai, `int` nahi.

```cpp
queue<TreeNode*> q;
```

* Flag ko **poora level complete hone ke baad** toggle karna hai.

---

## 🔑 Key Learning (Hinglish)

* Zigzag Traversal bhi **Level Order Traversal (BFS)** hi hai.
* Queue ka order kabhi change nahi hota.
* Children hamesha **Left → Right** hi push hote hain.
* Zigzag effect sirf output vector ko reverse karke aata hai.
* `flag` sirf direction batata hai.
* `return {};` function ke return type ki default value return karta hai (jaise vector ke liye empty vector).

---

## 💻 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr)
            return {};

        vector<vector<int>> finalans;
        queue<TreeNode*> q;

        q.push(root);

        int flag = 0;   // 0 = Left to Right, 1 = Right to Left

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* check = q.front();
                q.pop();

                level.push_back(check->val);

                if (check->left)
                    q.push(check->left);

                if (check->right)
                    q.push(check->right);
            }

            if (flag == 1)
                reverse(level.begin(), level.end());

            finalans.push_back(level);

            if (flag == 1)
                flag = 0;
            else
                flag = 1;
        }

        return finalans;
    }
};
```
