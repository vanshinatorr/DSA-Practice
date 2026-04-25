/*
========================================================
LeetCode 1614 - Maximum Nesting Depth of the Parentheses
========================================================

Problem:
Given a valid parentheses string s, return the maximum
nesting depth of parentheses.

Example:
Input: "(1+(2*3)+((8)/4))+1"
Output: 3


--------------------------------------------------------
Approach (Depth Counting - Optimal)
--------------------------------------------------------

Idea:
- Maintain current nesting depth.
- Whenever '(' appears:
      depth++
- Whenever ')' appears:
      depth--
- Track the maximum depth reached.

Example:
((()))

Step-by-step:
'(' -> depth =1, max=1
'(' -> depth =2, max=2
'(' -> depth =3, max=3
')' -> depth =2
')' -> depth =1
')' -> depth =0

Answer = 3


--------------------------------------------------------
Why This Works
--------------------------------------------------------

Every '(' means we go one level deeper.
Every ')' means we come one level out.

Maximum value of depth during traversal
is the maximum nesting depth.


--------------------------------------------------------
Complexity
--------------------------------------------------------

Time  : O(n)
Space : O(1)

Optimal:
- Cannot do better than O(n), because every character
  must be checked at least once.


--------------------------------------------------------
Common Mistakes (Avoided)
--------------------------------------------------------

1. Not initializing:
   int depth;   // garbage value ❌
   int depth=0; // correct ✅

2. Using assignment instead of comparison:
   if(s[i] = '(')   ❌
   if(s[i] == '(')  ✅

3. Using:
   else depth--;

Wrong because non-parenthesis chars would also reduce depth.

Correct:
else if(s[i] == ')')


--------------------------------------------------------
Code
--------------------------------------------------------
*/

class Solution {
public:
    int maxDepth(string s) {

        int depth = 0;
        int maxi  = 0;

        for(char c : s) {

            if(c == '(') {
                depth++;
                maxi = max(maxi, depth);
            }

            else if(c == ')') {
                depth--;
            }
        }

        return maxi;
    }
};
