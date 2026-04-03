/*
-------------------------------------------------------
🧩 Problem: Remove K Digits
https://leetcode.com/problems/remove-k-digits/submissions/1967862673/
-------------------------------------------------------
Given a number as string `num` and integer `k`,
remove k digits such that the new number is smallest.

-------------------------------------------------------
🧠 Approach: Monotonic Increasing Stack
-------------------------------------------------------
- Maintain a stack such that digits are in increasing order
- If current digit is smaller than top → pop (to minimize number)
- Repeat until k becomes 0

- If k still remains → remove from end

- Build result from stack
- Remove leading zeros
- Handle empty case

-------------------------------------------------------
⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

-------------------------------------------------------
🏷️ Tags:
Stack, Greedy, Monotonic Stack, String
-------------------------------------------------------
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char> st;

        // Step 1: Build monotonic increasing stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // Step 2: If k still remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: Build string from stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Step 4: Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        // Step 5: Handle empty case
        return ans.empty() ? "0" : ans;
    }
};
