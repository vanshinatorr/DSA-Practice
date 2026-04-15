
/*
🧩 Problem: Valid Anagram
https://leetcode.com/problems/valid-anagram/
------------------------------------------------------------
🧠 Problem Summary:
Given two strings s and t,
check whether they are anagrams.

👉 Anagram = same characters + same frequency
👉 Order does NOT matter

Example:
s = "anagram"
t = "nagaram"  → TRUE

------------------------------------------------------------
💡 Approach (Optimal - Frequency Count):

👉 Idea:
- Count characters of s (+1)
- Remove characters of t (-1)
- If all values become 0 → anagram

------------------------------------------------------------
⚙️ Steps:

1. Check length (must be equal)
2. Create freq array of size 26
3. Loop:
   +1 for s
   -1 for t
4. Check all values = 0

------------------------------------------------------------
❗ ALL YOUR DOUBTS (CLEAR CONCEPTS)

------------------------------------------------------------
🔹 1. vector<int> freq(26, 0) kya hai?

👉 vector = dynamic array (STL)

👉 (26, 0) ka matlab:
   - 26 → size
   - 0  → initial value

👉 Result:
   [0, 0, 0, 0, ... 26 times]

------------------------------------------------------------
🔹 2. Vector vs Array

👉 Array:
   int freq[26] = {0};

👉 Vector:
   vector<int> freq(26, 0);

✔️ Vector advantages:
   - dynamic size
   - built-in functions
   - safer

👉 Is problem me:
   ✔️ dono use ho sakte hain

------------------------------------------------------------
🔹 3. Ye 'a' minus kyu karte hain?

👉 freq[s[i] - 'a']

Example:
   'a' - 'a' = 0
   'b' - 'a' = 1
   'c' - 'a' = 2

👉 mapping:
   a → 0
   b → 1
   ...
   z → 25

👉 isliye 26 size ka array enough hai

------------------------------------------------------------
🔹 4. Capital letters ka kya?

👉 Ye code ONLY lowercase ke liye safe hai

Example:
   'A' - 'a' = negative ❌ (error)

👉 Solution:
   ✔️ convert to lowercase
   OR
   ✔️ use vector<int> freq(256, 0)

------------------------------------------------------------

------------------------------------------------------------
🔹 8. Time & Space Complexity

Time  : O(n)
Space : O(1)  (fixed size 26)
------------------------------------------------------------
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Step 1: Length check
        if (s.length() != t.length())
            return false; 

        // Step 2: Frequency array (a–z)
        vector<int> freq(26, 0);

        // Step 3: Count + Cancel
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;  // add for s
            freq[t[i] - 'a']--;  // subtract for t
        }

        // Step 4: Check all zero
        for (int count : freq) {
            if (count != 0) {
                return false; 
            }
        }

        return true; 
    }
};
