/*
-----------------------------------------
📌 Problem: Pow(x, n)
https://leetcode.com/problems/powx-n/
-----------------------------------------
Given a double x and integer n, calculate x raised to power n (x^n).

-----------------------------------------
🧠 Approach: Binary Exponentiation (Iterative - Even/Odd Version)
-----------------------------------------
- If power is negative:
    → Convert x = 1/x
    → Make power positive

- While power > 0:
    → If power is EVEN:
        - Square the base (x = x * x)
        - Reduce power by half
    → If power is ODD:
        - Multiply current x to answer (ans *= x)
        - Reduce power by 1

-----------------------------------------
⚡ Time Complexity:
O(log n)

-----------------------------------------
💾 Space Complexity:
O(1)

-----------------------------------------
⚠️ Edge Cases:
- n = INT_MIN → handled using long long
- x = 0
- negative powers

-----------------------------------------
🚫 Common Mistakes:
- Forgetting long long → overflow
- Missing loop → only 1 step executes
- Not handling negative power

-----------------------------------------
*/

class Solution {
public:
    double myPow(double x, int n) {
        
        long long power = n;   // handle overflow
        double ans = 1.0;

        // handle negative power
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        // main loop
        while (power > 0) {

            if (power % 2 == 0) {
                x = x * x;        // even → square
                power = power / 2;
            } 
            else {
                ans *= x;         // odd → take one x
                power = power - 1;
            }
        }

        return ans;
    }
};
