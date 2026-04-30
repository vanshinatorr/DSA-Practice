// File: modular_exponentiation.cpp

/*
-----------------------------------------------------
📌 Problem: Modular Exponentiation (x^n % M)   ( NOT IN STRIVER SHEET )
https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1?utm_source=chatgpt.com
-----------------------------------------------------

Given three integers x, n, and M,
calculate (x^n) % M efficiently.

-----------------------------------------------------
🧠 Intuition:
-----------------------------------------------------

Normal way:
- Compute x^n → then % M
❌ Problem: number becomes VERY large → overflow

Optimized way (Binary Exponentiation):
- Reduce number at every step using modulo
- Break power using divide by 2

-----------------------------------------------------
⚙️ Approach:
-----------------------------------------------------

1. Reduce base:
   base = x % M

2. Loop until power > 0:

   ➤ If power is EVEN:
       - square the base
       - divide power by 2

   ➤ If power is ODD:
       - multiply base to answer
       - reduce power by 1

3. Always take % M after multiplication

-----------------------------------------------------
⏱️ Complexity:
-----------------------------------------------------

Time  : O(log n)
Space : O(1)

-----------------------------------------------------
⚠️ Important Concepts:
-----------------------------------------------------

✔ Why use long long?

- base * base can overflow int
- int limit ≈ 2 * 10^9
- but multiplication can go beyond that
👉 So we use long long for safety

✔ Why modulo every time?

- To keep number small
- Avoid overflow
- Maintain correct result

✔ Condition logic:

- power % 2 == 0 → EVEN → square
- power % 2 == 1 → ODD  → multiply

-----------------------------------------------------
❌ Common Mistakes:
-----------------------------------------------------

1. ❌ Forgetting % M after multiplication
2. ❌ Using int instead of long long
3. ❌ Doing x^n first then % M (TLE / overflow)
4. ❌ Mixing even/odd logic

-----------------------------------------------------
🚫 Note:
-----------------------------------------------------

This question is NOT in Striver Sheet,
but VERY IMPORTANT for:
- Interviews
- Competitive Programming
- Google-level questions

-----------------------------------------------------
*/

class Solution {
public:
    int powMod(int x, int n, int M) {

        long long base = x % M;   // reduce base (important)
        long long power = n;
        long long ans = 1;

        while (power > 0) {

            if (power % 2 == 0) {          // even
                base = (base * base) % M;
                power /= 2;
            } 
            else {                         // odd
                ans = (ans * base) % M;
                power--;
            }
        }

        return ans;
    }
};
