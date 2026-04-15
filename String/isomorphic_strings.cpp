/* # 🧩 Problem: Isomorphic Strings (LeetCode 205)


   https://leetcode.com/problems/isomorphic-strings/
## 📌 Problem Statement

Given two strings `s` and `t`, determine if they are **isomorphic**.

Two strings are isomorphic if characters in `s` can be replaced to get `t`, with:

* Same order maintained
* One-to-one mapping (no two chars map to same char)

---

## 💡 Approach (Two Hash Maps)

We use:

* `mapST` → mapping from `s → t`
* `mapTS` → mapping from `t → s` (reverse check)

### Why two maps?

* First map ensures **consistency**
* Second map ensures **uniqueness (no collision)**

---

## ⚙️ Algorithm Steps

1. If lengths differ → return false
2. Traverse both strings
3. For each character pair:

   * Check `s → t` mapping
   * Check `t → s` mapping
4. If mismatch → return false
5. Otherwise → return true

---

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // Step 1: Length check
        if (s.length() != t.length()) return false;

        // Step 2: Create maps
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        // Step 3: Traverse strings
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // s -> t mapping check
            if (mapST.count(c1)) {
                if (mapST[c1] != c2)
                    return false;
            } else {
                mapST[c1] = c2;
            }

            // t -> s mapping check (reverse)
            if (mapTS.count(c2)) {
                if (mapTS[c2] != c1)
                    return false;
            } else {
                mapTS[c2] = c1;
            }
        }

        // Step 4: Valid mapping
        return true;
    }
};
```

---
  /*

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1) (max 256 chars)

---

## ❗ Common Mistakes

* Using only one map ❌
* Using `mp[key]` for checking (causes unwanted insertion) ❌
* Not handling reverse mapping ❌

---

## 🧠 Key Insight

> One map ensures mapping consistency, but two maps ensure **bijection (one-to-one mapping)**.

---

## 🚀 Bonus Optimization (Mention in Interview)

Instead of maps, we can use:

* Two arrays of size 256 → faster and constant space

---

## 🧪 Example

Input:

```
s = "badc"
t = "baba"
```

Output:

```
false
```

Reason:

* `d → b` conflicts with existing `b → b`
*/
---

## 💬 Interview One-Liner

> “I use two hash maps to maintain bidirectional mapping and ensure a one-to-one relationship between characters.”

---
