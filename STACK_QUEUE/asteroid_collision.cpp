 /*

🔹 Problem: Asteroid Collision (LeetCode 735)
   https://leetcode.com/problems/asteroid-collision/


==================================================

🧠 Intuition:

* Positive → right move → safe → push

* Negative → left move → collision possible

* Collision only when:
  st.back() > 0 && curr < 0

⚔️ Cases:

1. st.back() < abs(curr) → pop (smaller destroy)
2. st.back() == abs(curr) → pop (both destroy)
3. st.back() > abs(curr) → current destroy

============================================================
⏱ Time Complexity: O(N)
📦 Space Complexity: O(N)
=========================

*/

class Solution {
public:
vector<int> asteroidCollision(vector<int>& asteroids) {

```
    vector<int> st; // using vector as stack

    for (int i = 0; i < asteroids.size(); i++) {

        int curr = asteroids[i];

        // Case 1: positive → push directly
        if (curr > 0) {
            st.push_back(curr);
        }
        else {
            // Case 2: negative → collision

            // remove all smaller positives
            while (!st.empty() && st.back() > 0 && st.back() < abs(curr)) {
                st.pop_back();
            }

            // equal size → both destroy
            if (!st.empty() && st.back() == abs(curr)) {
                st.pop_back();
            }
            // safe to push
            else if (st.empty() || st.back() < 0) {
                st.push_back(curr);
            }
            // else current destroy → do nothing
        }
    }

    return st;
}
```

};

# /*

🔥 Key Notes (Revision):

* Always compare using abs(curr)
* Use while loop (multiple collisions possible)
* Vector can act as stack (push_back, pop_back, back)

🧠 Memory Trick:
"Negative aaye → chhote positives hatao → equal destroy → warna push"
=====================================================================

*/
