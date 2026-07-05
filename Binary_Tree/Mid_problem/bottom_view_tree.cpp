# Bottom View of Binary Tree

**Platform:** GFG
**Link:** https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

## Intuition (Hinglish)

Har node ka ek **Horizontal Distance (HD)** maintain karte hain.

* Root ka HD = `0`
* Left child = `HD - 1`
* Right child = `HD + 1`

Top View me har HD par **pehli node** store karte hain.

Bottom View me har HD par **latest (last) node** store karte rehte hain. Kyuki BFS level-order traversal karta hai, isliye neeche wali nodes baad me visit hoti hain. Is wajah se last stored node hi us HD ki Bottom View ban jati hai.

---

## Approach

1. Empty tree ho to empty vector return karo.
2. `map<int, Node*>` me har horizontal distance ki latest node store karo.
3. BFS ke liye `queue<tuple<Node*, int, int>>` use karo.
4. Har node visit karte hi:

   * Horizontal distance (`col`) nikalo.
   * `bottomnode[col] = node;` karke overwrite kar do.
5. Left child ko `(row + 1, col - 1)` aur right child ko `(row + 1, col + 1)` ke saath queue me push karo.
6. End me map ko left se right traverse karke answer bana do.

---

## Why This Works

* BFS level by level traverse karta hai.
* Har horizontal distance par last processed node hi sabse neeche visible hoti hai.
* `map` automatically horizontal distances ko sorted order me maintain karta hai.

---

## Time Complexity

* **Time:** `O(N log N)`
* **Space:** `O(N)`

---

## Key Learning (Hinglish)

* **Top View:** First node at every horizontal distance.
* **Bottom View:** Last node at every horizontal distance.
* Dono ka template same hai. Sirf ek line change hoti hai.

---

## Code

```cpp
/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {

        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        map<int, Node*> bottomnode;

        queue<tuple<Node*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            Node* node = get<0>(p);
            int row = get<1>(p);
            int col = get<2>(p);

            bottomnode[col] = node;

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        for (auto it : bottomnode) {
            ans.push_back(it.second->data);
        }

        return ans;
    }
};
```
