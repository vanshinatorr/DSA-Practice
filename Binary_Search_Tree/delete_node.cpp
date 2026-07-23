/*
========================================
Problem: Delete Node in a BST
Platform: LeetCode
Difficulty: Medium
https://leetcode.com/problems/delete-node-in-a-bst/submissions/2078667198/
========================================

Intuition:
- First search for the node.
- After finding it, handle one of the four deletion cases.
- If the node has two children, replace its value with its Inorder Successor.
- Delete the original successor node from the right subtree.

----------------------------------------

Approach:

1. Search the node
   - key < root->val  -> Left
   - key > root->val  -> Right
   - Otherwise -> Node Found

2. Handle 4 Cases

Case 1 : Leaf Node
- Return nullptr.

Case 2 : Only Right Child
- Return root->right.

Case 3 : Only Left Child
- Return root->left.

Case 4 : Two Children
- Find Inorder Successor.
- Copy successor value to current node.
- Delete successor from right subtree.
- Return root.

----------------------------------------

What is Inorder Successor?

Successor = Next Greater Node

It is always the minimum node in the right subtree.

Example:

        50
       /  \
     30    70
          /  \
        60    80

Successor of 50 = 60

----------------------------------------

Why do we delete the successor?

After copying:

        60
       /  \
     30    70
          /  \
        60    80

Now duplicate 60 exists.

Delete the original successor:

root->right = deleteNode(root->right, successor->val);

Final Tree:

        60
       /  \
     30    70
            \
             80

----------------------------------------

Helper Function

findMin(root)

Move left until left == nullptr.

The last node reached is the minimum node.

----------------------------------------

Time Complexity

O(H)

Worst Case : O(N)
Average BST : O(log N)

----------------------------------------

Space Complexity

O(H)

(Recursive Call Stack)

----------------------------------------

Key Learnings

- Search first, delete later.
- Always think in 4 deletion cases.
- Successor = Minimum node in Right Subtree.
- Copy successor value first.
- Delete original successor later.
- Updated subtree must be assigned back:
    root->left = ...
    root->right = ...
- Every recursive call returns the updated subtree.
- Always return root after updating.

========================================
*/
