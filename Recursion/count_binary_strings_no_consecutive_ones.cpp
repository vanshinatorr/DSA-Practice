/* # 📌 Problem: Consecutive 1's not allowed
https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1




Given an integer `n`, count all binary strings of length `n` such that **no two consecutive 1s** appear.

---

# 🚀 Approach 1: Iterative DP (Optimal)

## 💡 Idea

* If last bit is `0` → can come from any valid string of length `n-1`
* If last bit is `1` → previous must be `0` → from `n-2`
* So:

```
f(n) = f(n-1) + f(n-2)
```

---

## 💻 Code (Best Approach)

*/
```cpp
class Solution {
public:
    int countStrings(int n) {
        // Base cases
        if (n == 1) return 2;
        if (n == 2) return 3;

        int prev2 = 2; // f(1)
        int prev1 = 3; // f(2)

        // Build answer iteratively
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
```
/*
---

## ⚡ Complexity

* Time: O(n)
* Space: O(1) ✅

---

# 🧠 Approach 2: Recursion (Brute Force)

## 💡 Idea

Directly apply recurrence:

```
f(n) = f(n-1) + f(n-2)
```
*/


## 💻 Code (Recursive)

```cpp
class Solution {
public:
    
    int solve(int n) {
        // Base cases
        if (n == 1) return 2;
        if (n == 2) return 3;

        return solve(n - 1) + solve(n - 2);
    }
    
    int countStrings(int n) {
        return solve(n);
    }
};
```
/*
---

## ⚠️ Why Recursion is NOT Good Here

### ❌ Problems:

* Same calls repeat (overlapping subproblems)
* Example:

```
solve(5) calls solve(3) multiple times
```

### ⏱️ Complexity:

* Time: O(2^n) ❌ (very slow)
* Space: O(n) (recursion stack)

---

# 🔥 Why Iteration is Better

| Feature         | Recursion | Iteration |
| --------------- | --------- | --------- |
| Time Complexity | ❌ O(2^n)  | ✅ O(n)    |
| Space           | O(n)      | ✅ O(1)    |
| Speed           | Slow      | Fast      |
| Interview Value | Basic     | 🔥 Strong |

---

# 🎯 Key Takeaway

* Recursion helps understand the problem
* Iteration is used to **solve efficiently**

---

# 🚀 Final Recommendation

> Always write recursion first (for understanding),
> then convert to iterative DP for interviews.

---

# 🧠 Mistakes to Avoid

* ❌ Using plain recursion in interview
* ❌ Forgetting base cases
* ❌ Not optimizing space

---

# 📌 Summary

* This problem follows **Fibonacci pattern**
* Best solution uses **2 variables only**
* Important for **DP + recursion understanding**



  */
---
