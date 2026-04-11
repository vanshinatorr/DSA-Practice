
/*
===========================================================

🔹 Problem: Longest Common Prefix
🔹 Platform: LeetCode
🔹 Approach: Sorting + Compare First & Last
===========================================================

🧠 Problem Summary:
Given an array of strings, return the longest common prefix
among them. If none exists, return "".

-----------------------------------------------------------
💡 Approach (Sorting Based):
1. Sort the array of strings.
2. After sorting:
      - First string = lexicographically smallest
      - Last string  = lexicographically largest
3. Only compare these two strings:
      👉 Because they will have the maximum difference
4. Find common prefix between them.

-----------------------------------------------------------
🚀 Algorithm:
1. Sort strs
2. Take first = strs[0], last = strs[n-1]
3. Loop till min length of both:
      - If characters match → add to answer
      - Else → break
4. Return answer

-----------------------------------------------------------
⏱️ Complexity:
- Time: O(n log n + m)
        n = number of strings
        m = length of prefix
- Space: O(1)

imp:
// better approch h optimal nahi h 
// 20% log ye krte h 70 % optimal 
// but acceptable hai

-----------------------------------------------------------
⚠️ Common Mistakes:
❌ Forgetting to sort
❌ Using strs.size()-1 directly as string
❌ Not handling different string lengths
❌ Not breaking on mismatch

-----------------------------------------------------------
📌 Edge Cases:
- No common prefix → return ""
- Single string → return itself
- Empty strings present

===========================================================
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: Sort the array
        sort(strs.begin(), strs.end());

        // Step 2: Pick first and last strings
        string first = strs[0];
        string last  = strs[strs.size() - 1];

        string ans = "";

        // Step 3: Compare characters
        int len = min(first.size(), last.size());

        for (int i = 0; i < len; i++) {
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                break;
            }
        }

        return ans;
    }
};

/*
===========================================================
🧪 Example Dry Run:

Input: ["flower","flow","flight"]

After Sorting:
["flight","flow","flower"]

first = "flight"
last  = "flower"

Compare:
f == f ✅
l == l ✅
i != o ❌ stop

Output: "fl"

===========================================================
*/
