/*
=========================================================
Leetcode 1781 - Sum of Beauty of All Substrings
=========================================================

Problem:
Given a string s, return the sum of beauty of all substrings.

Beauty of a substring:
(maximum frequency among characters present)
-
(minimum frequency among characters present)

---------------------------------------------------------
Approach (Optimal O(n^2))
---------------------------------------------------------

Core Pattern:
Fix left pointer + expand right pointer + maintain frequency

For each starting index i:
1. Create fresh frequency array of size 26.
2. Extend substring using j from i to n-1.
3. Add current character into frequency.
4. Scan all 26 letters:
      - find maximum frequency
      - find minimum non-zero frequency
5. Add (max-min) to answer.

Why optimal?
Instead of generating each substring and recalculating
frequency from scratch, we incrementally grow substring
and reuse previous counts.

---------------------------------------------------------
Key Insight
---------------------------------------------------------

Example:
s = "aabcb"

Substrings starting at i=0:

"a"      beauty =0
"aa"     beauty =0
"aab"    beauty =1
"aabc"   beauty =1
"aabcb"  beauty =1

Incremental frequency reuse is the optimization.

---------------------------------------------------------
Complexity
---------------------------------------------------------

Outer loop     : O(n)
Inner loop     : O(n)
Frequency scan : O(26)

Total:
O(n^2 * 26) ≈ O(n^2)

Space:
O(26) = O(1)

---------------------------------------------------------
Common Mistakes I made / Debugging Notes
---------------------------------------------------------

1. Frequency array outside outer loop
   ❌ Carries dirty data across new starting points.

2. frequency[j]++
   ❌ j is string index, not alphabet index.

   Correct:
   freq[s[j]-'a']++

3. mn = 0
   ❌ zeros ruin minimum

   Correct:
   mn = INT_MAX

4. Forgetting:
   if(freq[k] > 0)

   ❌ absent letters (0) should not affect minimum.

5. sum += mx-mn inside frequency loop
   ❌ beauty added multiple times.

   Add once after max/min fully computed.

6. Confusing:
   for(auto k:freq)
   k is value, not index.

---------------------------------------------------------
Code
---------------------------------------------------------
*/

class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {

            // fresh frequency for each starting point
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {

                // grow substring by adding one char
                freq[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                // compute beauty of current substring
                for(int k = 0; k < 26; k++) {

                    if(freq[k] > 0) {
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }

                sum += (mx - mn);
            }
        }

        return sum;
    }
};


/*
=========================================================
Interview Pattern Learned
=========================================================

Whenever problem says:

- all substrings
- frequency based metric
- aggregate over every substring

Think:

Fix Left
Expand Right
Maintain Running State

Very common interview pattern.
=========================================================
*/
