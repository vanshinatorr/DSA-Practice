/*
===========================================================
Problem: Reverse Words in a String (LeetCode 151) ( med )
https://leetcode.com/problems/reverse-words-in-a-string/



Description:
Given a string s, reverse the order of words.
- Words are separated by spaces
- Remove extra spaces (leading, trailing, multiple)
- Return words separated by a single space

Example:
Input:  "  hello world  "
Output: "world hello"

===========================================================
Approach:
1. Reverse the entire string
2. Traverse and extract each word
3. Reverse each word back
4. Build result string with single spaces

===========================================================
Time Complexity: O(N)
Space Complexity: O(N)

===========================================================
Key Points:
- Use `i < n` to avoid out-of-bounds access
- Skip multiple spaces
- Add space only when needed

===========================================================
Common Mistakes:
- Forgetting to skip spaces
- Adding extra space at start/end
- Not handling last word properly
- Missing boundary check (i < n)

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        
        // Step 1: reverse full string
        reverse(s.begin(), s.end());
        
        for (int i = 0; i < n; i++) {
            
            // Skip spaces
            if (s[i] == ' ') continue;
            
            string word = "";
            
            // Extract word (with boundary check)
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            
            // Reverse word
            reverse(word.begin(), word.end());
            
            // Add space only if needed
            if (!ans.empty()) ans += " ";
            
            ans += word;
        }
        
        return ans;
    }
};

/*
===========================================================
Interview Notes:
- First give this solution (safe & clean)
- Then say: "We can optimize space to O(1) using in-place approach"
===========================================================
*/
