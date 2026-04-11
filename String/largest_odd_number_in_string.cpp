
/*
===========================================================
🔹 Problem: Largest Odd Number in String
https://leetcode.com/problems/largest-odd-number-in-string/description/
===========================================================

🧠 Problem Summary:
Given a numeric string `num`, return the largest-valued odd integer 
(as a substring of `num`). If no odd number exists, return an empty string.

-----------------------------------------------------------
💡 Approach:
- An odd number must end with an odd digit (1, 3, 5, 7, 9)
- To get the largest substring:
    👉 Find the RIGHTMOST odd digit
    👉 Return substring from index 0 to that position

-----------------------------------------------------------
🚀 Algorithm:
1. Traverse string from right → left
2. If digit is odd:
      return substring(0, i+1)
3. If no odd digit found → return ""

-----------------------------------------------------------
⏱️ Complexity:
- Time: O(n)
- Space: O(1)

-----------------------------------------------------------
⚠️ Common Mistakes:
❌ Not breaking after finding first odd digit → causes overwrite
❌ Checking from left instead of right
❌ Forgetting to convert char to int (num[i] - '0')

-----------------------------------------------------------
📌 Edge Cases:
- All digits even → return ""
- Single digit odd → return that digit
- Large input size (up to 1e5)

===========================================================
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        // Traverse from right to find first odd digit
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};

/*
===========================================================
🧪 Example Dry Run:

Input: "35427"

i = 4 → '7' → odd ✅
Return num.substr(0, 5) = "35427"

-----------------------------------------------------------

Input: "4206"

i = 3 → '6' → even ❌
i = 2 → '0' → even ❌
i = 1 → '2' → even ❌
i = 0 → '4' → even ❌

Return ""

===========================================================
*/
