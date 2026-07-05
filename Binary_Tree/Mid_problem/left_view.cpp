# Left View of Binary Tree

Platform: GeeksforGeeks  


---
  LINK: 
  
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=chatgpt.com
  
## Intuition (Hinglish)

Har level ki sabse pehli (leftmost) node hi Left View me dikhegi.

DFS use karte hain aur **Left → Right** order me traverse karte hain.

Jab kisi level par **pehli baar** pahunchte hain, wahi us level ki leftmost node hoti hai.

---

## Approach

1. Agar node `nullptr` ho to return.
2. Agar current level pe pehli baar aaye hain (`leftView.size() == level`), node ko answer me add karo.
3. Pehle **left subtree** traverse karo.
4. Fir **right subtree** traverse karo.
---

## Space Complexity

**O(H)**

`H` tree ki height hai. Ye recursion stack ki wajah se lagti hai.

- Worst Case: **O(N)**
- Balanced Tree: **O(log N)**

---

## Code

```cpp
class Solution {
public:

    void getLeftView(Node* root, vector<int>& leftView, int level) {

        if (root == nullptr) {
            return;
        }

        if (leftView.size() == level) {
            leftView.push_back(root->data);
        }

        getLeftView(root->left, leftView, level + 1);
        getLeftView(root->right, leftView, level + 1);
    }

    vector<int> leftView(Node* root) {

        vector<int> leftView;

        getLeftView(root, leftView, 0);

        return leftView;
    }
};
```

---

## Key Learning

- Tree ke **Left View** ko DFS se efficiently solve kar sakte hain.
- Traversal order hi decide karta hai kaunsa view milega.
  - **Left View:** Left → Right
  - **Right View:** Right → Left
- `view.size() == level` ka matlab hai **is level par pehli baar aaye hain**, isliye wahi visible node answer me add karte hain.
