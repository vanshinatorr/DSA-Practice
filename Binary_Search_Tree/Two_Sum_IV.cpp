
# 653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/2088675237/

## Pattern
- BST Iterator
- Two Pointers
- Stack

---

## Idea

The inorder traversal of a BST is always sorted.

So we use:
- `next()` → returns the next smallest value.
- `before()` → returns the next largest value.

This is exactly the same as the Two Pointer approach on a sorted array.

```
Smallest ------------------> Largest
    left                     right
```

---

## Steps

1. Push all left nodes into `leftStack`.
2. Push all right nodes into `rightStack`.
3. Get the smallest value using `next()`.
4. Get the largest value using `before()`.
5. While `left < right`
   - If `left + right == k` → return `true`
   - If `left + right < k` → move the left pointer
   - Else → move the right pointer

---

## Helper Functions

### pushAllLeft()

Pushes the complete left boundary into the stack.

### pushAllRight()

Pushes the complete right boundary into the stack.

### next()

Returns the next smallest value.

### before()

Returns the next largest value.

---

## Code

```cpp
class Solution {
public:
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;

    // Push all left nodes
    void pushAllLeft(TreeNode* root) {

        while (root != nullptr) {
            leftStack.push(root);
            root = root->left;
        }
    }

    // Push all right nodes
    void pushAllRight(TreeNode* root) {

        while (root != nullptr) {
            rightStack.push(root);
            root = root->right;
        }
    }

    // Return next smallest value
    int next() {

        TreeNode* temp = leftStack.top();
        leftStack.pop();

        if (temp->right != nullptr)
            pushAllLeft(temp->right);

        return temp->val;
    }

    // Return next largest value
    int before() {

        TreeNode* temp = rightStack.top();
        rightStack.pop();

        if (temp->left != nullptr)
            pushAllRight(temp->left);

        return temp->val;
    }

    bool findTarget(TreeNode* root, int k) {

        if (root == nullptr)
            return false;

        pushAllLeft(root);
        pushAllRight(root);

        int left = next();
        int right = before();

        while (left < right) {

            int sum = left + right;

            if (sum == k)
                return true;

            else if (sum < k)
                left = next();

            else
                right = before();
        }

        return false;
    }
};
```

---

## If the Question Asked to Return the Pair

Only the return type and return statement change.

```cpp
pair<int, int> findTarget(TreeNode* root, int k)
```

Inside the loop:

```cpp
if (sum == k)
    return {left, right};
```

If no pair exists:

```cpp
return {-1, -1};
```

> **Everything else remains exactly the same.**
>
> `next()`, `before()`, `pushAllLeft()`, and `pushAllRight()` do not change.

---

## Complexity

**Time:** `O(n)`

**Space:** `O(h)`

`h = Height of BST`

---

## Common Mistakes

❌ Using

```cpp
while (left <= right)
```

✔️ Correct

```cpp
while (left < right)
```

---

❌ In `next()`

```cpp
pushAllLeft(temp->left);
```

✔️ Correct

```cpp
pushAllLeft(temp->right);
```

---

❌ In `before()`

```cpp
pushAllRight(temp->right);
```

✔️ Correct

```cpp
pushAllRight(temp->left);
```

---

❌ Forgetting to initialize the left stack

```cpp
pushAllLeft(root);
```

---

❌ Forgetting to initialize the right stack

```cpp
pushAllRight(root);
```

---

## Remember Pattern

```text
pushAllLeft()  -> next()    -> Smallest

pushAllRight() -> before()  -> Largest

left = next()
right = before()

while (left < right)

sum == k  -> return true

sum < k   -> left = next()

sum > k   -> right = before()
```
