## Lowest Common Ancestor of a Binary Tree (LeetCode 236)

**Platform:** LeetCode
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/2059601911/


#  Intuition

Har recursive call sirf **ek question ka answer deti hai**:

> **"Mere subtree me `p` ya `q` mila kya?"**

Recursion kabhi directly LCA dhoondhne nahi jaati.

Wo parent ko sirf information return karti hai:

* `nullptr` → kuch nahi mila
* `p` → p mila
* `q` → q mila
* `LCA node` → answer mil gaya

Jab kisi node ko

* left subtree se ek target
* right subtree se doosra target

mil jata hai, wahi node **Lowest Common Ancestor** ban jata hai.

---

# Approach

### 1. Base Case

```cpp
if(root == nullptr)
    return nullptr;
```

Tree khatam.

Kuch nahi mila.

---

### 2. Current Node Check

```cpp
if(root == p || root == q)
    return root;
```

Agar current node hi target hai to usi node ko return karo.

Parent ko information bhejni hai ki **kaun mila**.

---

### 3. Search Left & Right

```cpp
TreeNode* left = lowestCommonAncestor(root->left, p, q);
TreeNode* right = lowestCommonAncestor(root->right, p, q);
```

Dono subtree se information collect karo.

---

### 4. Decision Making

#### Case 1

```cpp
left != nullptr
right != nullptr
```

Matlab

* ek node left me
* ek node right me

Current node hi LCA hai.

```cpp
return root;
```

---

#### Case 2

```cpp
left != nullptr
right == nullptr
```

Sirf left me mila.

Usi ko upar pass kar do.

```cpp
return left;
```

---

#### Case 3

```cpp
left == nullptr
right != nullptr
```

Sirf right me mila.

```cpp
return right;
```

---

#### Case 4

```cpp
left == nullptr
right == nullptr
```

Kahin bhi nahi mila.

```cpp
return nullptr;
```

---

# Decision Table

| Left | Right | Return     |
| ---- | ----- | ---------- |
| NULL | NULL  | NULL       |
| Node | NULL  | Left       |
| NULL | Node  | Right      |
| Node | Node  | Root (LCA) |

---

# Why It Works

Har node apne parent ko sirf information return karta hai.

Jab parent ko dono subtrees se non-null value milti hai, iska matlab dono targets alag branches me hain.

Isliye current node hi Lowest Common Ancestor hota hai.

---

# Time Complexity

```
O(N)
```

Har node sirf ek baar visit hota hai.

---

# Space Complexity

```
O(H)
```

`H` = Height of Tree (Recursion Stack)

* Balanced Tree → `O(log N)`
* Skewed Tree → `O(N)`

---

# C++ Code

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr)
            return nullptr;

        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        if (left)
            return left;

        if (right)
            return right;

        return nullptr;
    }
};
```

---

# Key Learning

* **Recursive function LCA nahi dhoondti, information return karti hai.**
* **Return value ka matlab samajhna recursion ka sabse important part hai.**
* Har call sirf batati hai:

  * `nullptr` → kuch nahi mila
  * `p/q` → target mila
  * `root` → LCA mil gaya
* **Jab left aur right dono non-null ho jaye, current node answer ban jata hai.**
