/*
========================================================
LeetCode 13 - Roman to Integer
https://leetcode.com/problems/roman-to-integer/
========================================================

Problem:
Convert Roman numeral string into integer.

--------------------------------------------------------
Roman Symbol Mapping
--------------------------------------------------------

I  -> 1
V  -> 5
X  -> 10
L  -> 50
C  -> 100
D  -> 500
M  -> 1000


--------------------------------------------------------
Approach (Add Case Checked First)
--------------------------------------------------------

Instead of checking subtraction case:

if(current < next)
   subtract

We invert logic and check ADD case first.

Add when:
1) Current is last character
OR
2) Current value >= next value

Otherwise subtract.


--------------------------------------------------------
Core Condition
--------------------------------------------------------

if(i+1 == s.size() || mp[s[i]] >= mp[s[i+1]])

Meaning:

Case 1:
i+1 == s.size()

agar last character hu
to bas add karo
next mat dekho


We are at last character.
No next element exists.
So just add.

----------------------------------

Case 2:
current >= next

Normal additive case.

Example:
VI

5 >=1

Add 5.

----------------------------------

Else:

current < next

Subtractive case.

Example:
IV

1 <5

Subtract 1.


--------------------------------------------------------
Dry Run
--------------------------------------------------------

MCMXCIV

M add
C subtract
M add
X subtract
C add
I subtract
V add

1994


--------------------------------------------------------
Complexity
--------------------------------------------------------

Time  : O(n)
Space : O(1)

Optimal.


--------------------------------------------------------
Common Mistakes Avoided
--------------------------------------------------------

1. int ans must start from 0

2. Boundary check:
i+1 == s.size()

Avoids out-of-bounds.

3. Using OR:

if(last char || additive case)


--------------------------------------------------------
Code
--------------------------------------------------------
*/

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            if(i+1 == s.size() || mp[s[i]] >= mp[s[i+1]]) {
                ans += mp[s[i]];
            }
            else {
                ans -= mp[s[i]];
            }
        }

        return ans;
    }
};
