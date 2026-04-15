
/*
🧩 Problem: 796. Rotate String (LeetCode - Easy)
https://leetcode.com/problems/rotate-string/
------------------------------------------------------------
🧠 Problem Summary:
Given two strings s and goal,
check whether s can become goal after some rotations.

Rotation = leftmost character ko end me daal dena.

Example:
s = "abcde"
→ "bcdea" → "cdeab" ...

------------------------------------------------------------
💡 Optimal Approach (Important Trick):

👉 If goal is rotation of s,
then goal MUST be a substring of (s + s)

Why?
Because s + s represents all possible rotations.

Example:
s = "abcde"
s+s = "abcdeabcde"

All rotations exist inside this string.

------------------------------------------------------------
⚙️ Steps:

1. Length check (must be equal)
2. temp = s + s
3. Check if goal is substring of temp

------------------------------------------------------------
⏱️ Complexity:

Time  : O(n)
Space : O(n)

------------------------------------------------------------
❗ Important Concepts / Confusions:

1. 🔥 Why NOT use:
   if (temp.find(goal))

   Because:
   find() returns index, NOT boolean

   Case:
   temp.find(goal) = 0  (found at index 0)

   In C++:
   if(0) → false ❌

   So correct way:
   👉 temp.find(goal) != string::npos


2. 🔥 What is string::npos?

   - Special constant in C++
   - Means: "not found"
   - Type: size_t (unsigned)
   - Value: very large number (max possible)

   So:
   find() returns:
   - index (0,1,2...) → found
   - string::npos → not found


3. 🔥 Why NOT use -1 ?

   find() returns size_t (unsigned)

   If you write:
   temp.find(goal) == -1

   Internally:
   -1 gets converted to large unsigned value

   So it MAY work, but:
   ❌ Not clean
   ❌ Bad practice
   ❌ Confusing in interviews

   👉 Always use string::npos


4. 🔥 Why NOT directly use if condition?

   Wrong:
   if(temp.find(goal))

   Correct:
   if(temp.find(goal) != string::npos)

------------------------------------------------------------
🚀 Final Thought:

Rotation problem → convert into substring problem

------------------------------------------------------------
*/


class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // Step 1: Length check
        if (s.length() != goal.length()) return false;

        // Step 2: Create double string
        string temp = s + s;

        // Step 3: Substring check
        if (temp.find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};
