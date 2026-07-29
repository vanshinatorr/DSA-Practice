# LeetCode 173 - BST Iterator

## Pattern
> Stack + Left Path

---

## Idea

- Do not store full inorder.
- Store only the left path in the stack.
- `next()` always returns the next smallest value.

---

## Steps

### Constructor

- Push all left nodes from root.

### next()

1. Get top node.
2. Pop it.
3. If it has a right child, push all left nodes of its right subtree.
4. Return node value.

### hasNext()

- Return `true` if stack is not empty.

---

## Helper

```cpp
void pushAllLeft(TreeNode* root)
{
    while(root != nullptr)
    {
        st.push(root);
        root = root->left;
    }
}
```

---

## Code

```cpp
class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* root)
    {
        while(root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root)
    {
        pushAllLeft(root);
    }

    int next()
    {
        TreeNode* temp = st.top();
        st.pop();

        if(temp->right != nullptr)
            pushAllLeft(temp->right);

        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
```

---

## Complexity

- **Constructor:** `O(h)`
- **next():** `O(1)` (Amortized)
- **hasNext():** `O(1)`
- **Space:** `O(h)`

> `h = Height of BST`

---

## Common Mistakes

❌ `st.push_back()` → ✅ `st.push()`

❌ `int temp = st.top()` → ✅ `TreeNode* temp = st.top()`

❌ `return temp` → ✅ `return temp->val`

❌ Forget `root = root->left` → Infinite loop

❌ `st.size() != nullptr` → ✅ `!st.empty()`
