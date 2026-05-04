/*

## 🧩 Problem  : https://www.geeksforgeeks.org/problems/sort-a-stack/1

Sort a stack using recursion (without using any extra data structure).

---

## 💡 Approach

We use **recursion + insertion logic**:

1. **Pop all elements** recursively until stack becomes empty
2. While returning back (backtracking), **insert each element in sorted order**
3. `insertsort()` ensures correct position of element

---

## ⚙️ Sorting Logic

* Condition:

  ```cpp
  st.empty() || st.top() <= x
  ```

  👉 Ensures **Top = Largest element**
  👉 Stack becomes: **Descending (top → bottom)**

---

## 🚀 Code
*/
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper function to insert element in sorted stack
    void insertsort(stack<int> &st, int x) {

        // Base condition: correct position found
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        // Remove top element
        int temp = st.top();
        st.pop();

        // Recursive call
        insertsort(st, x);

        // Put back removed element
        st.push(temp);
    }

    // Main function to sort stack
    void sortStack(stack<int> &st) {

        // Base condition
        if (st.empty()) return;

        // Remove top element
        int x = st.top();
        st.pop();

        // Sort remaining stack
        sortStack(st);

        // Insert element at correct position
        insertsort(st, x);
    }
};
```

---

  /*

## 📊 Complexity

* **Time Complexity:** `O(N^2)`
  👉 Each insert may traverse stack

* **Space Complexity:** `O(N)`
  👉 Recursive call stack

---

## ⚠️ Common Mistakes

* ❌ Using `st.top() >= x` (this changes order)
* ❌ Forgetting to push back `temp`
* ❌ Confusing ascending definition (top vs bottom)

---

## ✅ Final Behavior

Input (top → bottom):

```
3
1
2
```

Output:

```
3
2
1
```

👉 **Top = Largest (default expected in interviews)**

---

## 🧠 Key Insight

👉 Changing just this line:

```cpp
st.top() <= x
```

➡️ Controls entire stack order

---

## 🔥 Interview Tip

If question doesn’t specify:
👉 Always assume **Top = Largest**
*/
