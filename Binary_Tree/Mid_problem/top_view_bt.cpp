# Top View of Binary Tree (GFG)

**Platform:** GeeksforGeeks

 Link  https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=chatgpt.com

## Hinglish Intuition

Top View me hume har **vertical line (horizontal distance/column)** ka **sabse upar wala node** chahiye.

Tree ko level by level (BFS) traverse karte hain.

Har node ke saath uska **horizontal distance (HD)** maintain karte hain:

* Root → `0`
* Left → `HD - 1`
* Right → `HD + 1`

Ek `map<HD, Node*>` rakhte hain.

Jab kisi HD par **pehli baar** node mile, usse map me store kar dete hain.

Kyuki BFS level-order me chalti hai, jo node pehle milegi wahi us column ki topmost node hogi.

Finally map ko left se right iterate karke answer bana dete hain.

---

## Approach

1. Agar root `NULL` ho to empty vector return karo.
2. `map<int, Node*> topNode` banao.
3. Queue me `(node, row, col)` push karo.
4. BFS start karo.
5. Agar current column map me nahi hai to current node store karo.
6. Left child ko `(row+1, col-1)` ke saath push karo.
7. Right child ko `(row+1, col+1)` ke saath push karo.
8. BFS complete hone ke baad map traverse karke node values answer me push kar do.

> **Note:** `row` is solution me use nahi ho raha. Sirf `col` se bhi solution ban sakta hai.

---

## Why This Works

* BFS level by level traverse karti hai.
* Isliye kisi bhi column par jo node sabse pehle visit hoti hai wahi topmost hoti hai.
* Map columns ko automatically sorted order me store karta hai.
* Isliye final answer left se right mil jata hai.

---

## Time Complexity

* **O(N log N)**

  * `N` nodes visit hote hain.
  * Har insertion/search map me `O(log N)`.

## Space Complexity

* **O(N)**

  * Queue + Map.

---

## Key Learning (Hinglish)

* Top View me **first node of every horizontal distance** store karni hoti hai.
* BFS use karte hain kyuki woh naturally top-to-bottom traverse karti hai.
* `map<int, Node*>` columns ko sorted order me rakhta hai.
* Pehli baar kisi column par node mile to hi store karo.
* `row` maintain karna optional hai; BFS ke saath sirf `col` bhi enough hai.

---

## C++ Code

```cpp
class Solution {
public:
    vector<int> topView(Node *root) {

        vector<int> ans;

        if (root == nullptr)
            return {};

        map<int, Node*> topNode;

        queue<tuple<Node*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            Node* node = get<0>(p);
            int row = get<1>(p);
            int col = get<2>(p);

            if (topNode.find(col) == topNode.end()) {
                topNode[col] = node;
            }

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        for (auto it : topNode) {
            ans.push_back(it.second->data);
        }

        return ans;
    }
};
```

**Interview Tip:** Agar interviewer bole optimize karo, to `queue<pair<Node*, int>>` use karo. `row` ki Top View me zarurat nahi hoti.
