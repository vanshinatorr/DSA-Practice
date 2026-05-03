/*
===========================================


on GfG not an striver Problem 

🔹 Problem: Count Characters with Exactly K Groups
https://www.geeksforgeeks.org/problems/count-the-characters1821/1
===========================================

Given a string s, count how many characters appear in exactly k groups.

👉 Important:
- Consecutive same characters = 1 group
- We are counting GROUPS, not frequency

-------------------------------------------
🧠 Example:
s = "aabbaaa"

Groups:
aa | bb | aaa

a → 2 groups
b → 1 group

-------------------------------------------
🎯 Goal:
Return number of characters whose group count == k
-------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();

        /*
        ===========================================
        🔹 Approach: Using i+1 (Group END detection)
        ===========================================

        Condition:
        - If current != next → group ends
        - If last index → force group end

        Why needed?
        - Because s[i+1] is invalid at last index
        */

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                mp[s[i]]++;
            }
        }

        int count = 0;

        for (auto &c : mp) {
            if (c.second == k) {
                count++;
            }
        }

        return count;
    }
};


/*
===========================================
⚡ Alternative Approach (Recommended)
===========================================

👉 Using i-1 (Group START detection)

Cleaner and safer (no boundary issue)

-------------------------------------------

for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
        mp[s[i]]++;
    }
}

-------------------------------------------

🧠 Difference:

i-1 → Detects START of group
i+1 → Detects END of group

-------------------------------------------

⚖️ Comparison:

| Approach | Type         | Clean | Safe |
|----------|-------------|------|------|
| i-1      | Group Start | ✅   | ✅   |
| i+1      | Group End   | ❌   | ⚠️ needs extra check |

-------------------------------------------

💡 Why industry prefers i-1:

- No out-of-bounds issue
- No special last index handling
- Easier to reason in interviews

===========================================
*/


/*
===========================================
⏱ Complexity
===========================================

Time Complexity:  O(n)
Space Complexity: O(1) (at most 26 chars)

===========================================
*/


/*
===========================================
🚨 Common Mistakes
===========================================

❌ Using = instead of ==
❌ Using unordered_map<int, char>
❌ Confusing frequency with groups
❌ Forgetting last index in i+1 approach

===========================================
*/


/*
===========================================
🔥 Key Takeaway
===========================================

👉 Always clarify:
- Are we counting frequency?
- Or groups?

👉 “Consecutive” keyword → GROUP problem

===========================================
*/
