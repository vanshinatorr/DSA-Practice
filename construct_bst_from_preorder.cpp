# LC 1008 - Construct BST from Preorder

## Approach

- Traverse preorder only once.
- Maintain one global `index`.
- Every recursive call builds one subtree.
- Every subtree has one rule:
  - **Maximum allowed value (Upper Bound).**

---

## Code

```cpp
class Solution {
public:
    int index = 0;

    TreeNode* build(vector<int>& preorder, int upperBound) {

        // No elements left
        if (index == preorder.size())
            return nullptr;

        // Current value does not belong to this subtree
        if (preorder[index] > upperBound)
            return nullptr;

        // Create current node
        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        // Build left subtree
        root->left = build(preorder, root->val);

        // Build right subtree
        root->right = build(preorder, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};
```

---

# Pattern

```text
build(UpperBound)

↓

Value > UpperBound ?

↓

YES
return nullptr

↓

NO
Create Node

↓

index++

↓

Left
build(Current Node Value)

↓

Right
build(Old UpperBound)

↓

return root
```

---

# Remember

### Global Index

```text
One traversal only.

Node Created
↓

index++

Node Rejected
↓

Index remains same
```

---

### Upper Bound

```text
Maximum value allowed
for current subtree.
```

---

### Left Rule

```text
New Upper Bound

↓

Current Node
```

---

### Right Rule

```text
Old Upper Bound

↓

Inherited from Parent
```

---

### Reject Rule

```text
Reject

≠ Invalid

Reject

= Not my subtree
```

---

# Interview Explanation (30 sec)

```text
We traverse preorder only once using a global index.

Each recursive call builds one subtree.

The subtree receives an upper bound.

If the current value exceeds the upper bound,
it cannot belong to this subtree,
so we return nullptr without consuming the value.

Otherwise we create the node,
move the index,
build the left subtree with the current node as the new upper bound,
and build the right subtree with the inherited upper bound.
```

---

# Complexity

```text
Time  : O(N)

Space : O(H)
```
