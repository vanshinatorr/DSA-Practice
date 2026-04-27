/*
=========================================================
LeetCode 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
=========================================================

Problem:
Given a string s, return the longest palindromic substring in s.

Examples:
Input:  "babad"
Output: "bab" or "aba"

Input: "cbbd"
Output: "bb"


---------------------------------------------------------
Approach: Expand Around Center
---------------------------------------------------------

Idea:
Every palindrome has a center.

Two possibilities:
1. Odd length palindrome
   Example: "racecar"
            center = e

2. Even length palindrome
   Example: "abba"
            center between two b's

For every index i:
- Expand taking i as center (odd)
- Expand taking i and i+1 as center (even)

Keep track of longest palindrome found.

---------------------------------------------------------
Why return right-left-1 ?
---------------------------------------------------------

During expansion:

while(valid palindrome){
    left--;
    right++;
}

Pointers overshoot one step beyond palindrome.

Example:
abba

Valid palindrome:
1..4

After one extra expansion:
0..5

Length:
right-left-1

---------------------------------------------------------
Updating boundaries:
---------------------------------------------------------

start = i-(len-1)/2
end   = i+len/2

Works for both:
Odd:
aba

Even:
abba

---------------------------------------------------------
Time Complexity:
O(n^2)

Space Complexity:
O(1)

---------------------------------------------------------
Mistakes to Avoid:
- Using if instead of while in expand()
- Writing right-left+1 instead of right-left-1
- Forgetting even center (i, i+1)
- Using substr(start,end) instead of
  substr(start,end-start+1)
=========================================================
*/

class Solution {
public:

    // Expand from center and return palindrome length
    int expand(string s, int left, int right) {

        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        // remove one overshot expansion
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            // Update longest palindrome
            if(len > end - start + 1) {

                start = i - (len - 1)/2;
                end   = i + len/2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
