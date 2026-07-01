# LeetCode 987 - Vertical Order Traversal of a Binary Tree
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/2052604822/

* **LeetCode 987**
* **Topic:** Binary Tree, BFS, Map, Multiset

---

# Intuition (Hinglish)

Is question me hume tree ko **vertical columns** ke hisaab se print karna hai.

Har node ki ek position (coordinate) maan lete hain.

* Root = `(column = 0, row = 0)`
* Left child = `(column - 1, row + 1)`
* Right child = `(column + 1, row + 1)`

Ab hume har node ko uske **column** aur **row** ke according store karna hai.

Isliye use karte hain:

```cpp
map<int, map<int, multiset<int>>> nodes;
```

* Outer `map` → Column ko sort karega (Left → Right)
* Inner `map` → Row ko sort karega (Top → Bottom)
* `multiset` → Agar same row aur same column me multiple nodes aa jaye to values ascending order me store hongi.

Coordinates maintain karne ke liye BFS use karte hain.

Queue me har node ke saath uska `(row, column)` bhi store karte hain.

BFS complete hone ke baad map ko traverse karke answer bana dete hain.

---

# Approach

1. Root ko `(0,0)` coordinate ke saath queue me push karo.
2. BFS chalao.
3. Har node ko `nodes[column][row]` me insert karo.
4. Left child:

   * `row + 1`
   * `column - 1`
5. Right child:

   * `row + 1`
   * `column + 1`
6. BFS complete hone ke baad outer map aur inner map traverse karo.
7. Multiset ki values answer me add kar do.

---

# Why BFS?

* Har node ke saath `(row, column)` coordinate carry karna easy hota hai.
* Level-wise traversal naturally ho jati hai.

---

# Data Structure Used

```cpp
map<int, map<int, multiset<int>>> nodes;
```

Meaning:

```text
Column
   |
   ---> Row
            |
            ---> Sorted Values
```

Example:

```text
nodes

-1
   1 -> {9}

0
   0 -> {3}
   2 -> {15}

1
   1 -> {20}

2
   2 -> {7}
```

---

# Time Complexity

* Insertion in map/multiset takes `log N`
* Total:

**TC:** `O(N log N)`

---

# Space Complexity

**SC:** `O(N)`

---

# Key Learning (Hinglish)

* Vertical Traversal me sabse important cheez **coordinates** hain.
* Hum khud coordinates define karte hain.
* Column answer me pehle aata hai isliye outer map column ka hota hai.
* Same `(row, column)` ke liye `multiset` use hota hai.
* Queue me sirf node nahi, uska coordinate bhi store karna padta hai.
* Ye question logic se zyada STL implementation ka hai.

---

# Code

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0}); // (node, row, column)

        while (!q.empty()) {

            auto p = q.front();
            q.pop();

            TreeNode* node = get<0>(p);
            int row = get<1>(p);
            int col = get<2>(p);

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, row + 1, col - 1});

            if (node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> ans;

        for (auto column : nodes) {

            vector<int> temp;

            for (auto level : column.second) {

                for (auto val : level.second) {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
```
