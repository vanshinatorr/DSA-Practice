# Floor and Ceil in BST

**Platform:** GeeksforGeeks

* **Floor:** https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
* **Ceil:** https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

---

# Intuition

A BST works like **Binary Search on a Tree**.

At every node, there are only three cases:

* Equal → Answer found.
* Smaller → Go Right.
* Greater → Go Left.

---

# Floor in BST

**Definition:**
The **Floor** is the **largest value that is less than or equal to the target**.

### Rules

* `root->data == key` → Return the value.
* `root->data < key` → This can be the floor. Save it and move to the **right**.
* `root->data > key` → This cannot be the floor. Move to the **left**.

### Easy Pattern

```text
Equal   → Return
Smaller → Save + Right
Greater → Left
```

---

# Ceil in BST

**Definition:**
The **Ceil** is the **smallest value that is greater than or equal to the target**.

### Rules

* `root->data == key` → Return the value.
* `root->data > key` → This can be the ceil. Save it and move to the **left**.
* `root->data < key` → This cannot be the ceil. Move to the **right**.

### Easy Pattern

```text
Equal   → Return
Greater → Save + Left
Smaller → Right
```

---

# Why It Works

### Floor

If the current node is smaller than the target:

* It can be the answer.
* A better (larger) floor may exist in the right subtree.
* So, **save it and go right**.

### Ceil

If the current node is greater than the target:

* It can be the answer.
* A better (smaller) ceil may exist in the left subtree.
* So, **save it and go left**.

---

# Time Complexity

* **Time:** `O(H)`

  * Balanced BST: `O(log N)`
  * Skewed BST: `O(N)`

* **Space:** `O(1)` (Iterative)

---

# Key Takeaway

Think of a BST as **Binary Search on a Tree**.

```text
Floor
------
Equal   → Return
Smaller → Save + Right
Greater → Left

Ceil
-----
Equal   → Return
Greater → Save + Left
Smaller → Right
```

---

