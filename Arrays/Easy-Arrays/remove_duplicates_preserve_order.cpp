/* ### 📌 Problem: Remove Duplicates While Preserving Order

 Common interview problem (AMCAT / basic DSA concept)
 not an striver sheet problem 

---

### 🧠 Problem Statement

Given an array of integers, remove duplicate elements **while preserving the original order** of elements.

---

### 🧾 Example

```
Input:  [1, 1, 3, 2, 1, 4, 5, 4]
Output: [1, 3, 2, 4, 5]
```

---

### 💡 Approach

* Use `unordered_set` to track already seen elements
* Traverse array once
* If element is not in set:

  * Add to result
  * Mark as seen

---

### ⚙️ Code (C++)

```cpp
// File: remove_duplicates.cpp

#include <bits/stdc++.h>
using namespace std;

/*
    Function: removeDuplicate
    --------------------------------
    Removes duplicates from array while preserving order

    Parameters:
        arr - input array

    Returns:
        vector<int> - array with duplicates removed
*/

vector<int> removeDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;

    for (int x : arr) {
        // Check if element is not seen before
        if (seen.find(x) == seen.end()) {
            result.push_back(x);  // preserve order
            seen.insert(x);       // mark as seen
        }
    }

    return result;
}
```
/*
---

### ⏱ Complexity

* **Time:** O(N)
* **Space:** O(N)

---

### 🚫 Common Mistakes

* Using only vector → leads to O(N²)
* Using set → destroys original order
* Forgetting `seen.insert(x)` → duplicates not tracked

---

### 🧠 Key Insight

> "Vector preserves order, unordered_set ensures fast duplicate detection."

---

### 🎯 Interview Tip

Explain like this:

> "Since the array is unsorted and order must be preserved, I use a hash set for O(1) lookup and a vector to maintain insertion order."

---

### 📌 Similar Problems to Practice

* First non-repeating element
* Frequency count using hashmap
* Remove duplicates from string
*/
