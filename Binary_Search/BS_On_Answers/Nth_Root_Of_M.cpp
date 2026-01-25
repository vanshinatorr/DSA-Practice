/* # Find Nth Root of a Number (Binary Search)


https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=SUBMISSION  
solved on code360


## Problem Statement
You are given two positive integers `n` and `m`.
Return the **integer nth root of m**, i.e. a number `x` such that:

x^n = m

If the nth root of `m` is **not an integer**, return `-1`.

---

## Examples

Input:
n = 3, m = 27  
Output:
3  
Explanation:
3^3 = 27

Input:
n = 2, m = 10  
Output:
-1  
Explanation:
No integer x exists such that x^2 = 10

---

## Approach (Binary Search)

- Possible answer range lies between `1` and `m`
- Use **Binary Search** to reduce time complexity
- For each `mid`, calculate `mid^n` manually
- If `mid^n == m`, return `mid`
- If `mid^n > m`, search left
- If `mid^n < m`, search right

### Important Points
- `^` operator in C++ is **XOR**, not power
- Power is calculated using a loop
- Early break is used to avoid overflow

---

## Algorithm
1. Set `low = 1`, `high = m`
2. While `low <= high`:
   - Calculate `mid`
   - Compute `mid^n`
   - Compare with `m`
3. Return result or `-1`

-------------- */


int NthRoot(int n, int m) {

    int low = 1;            // nth root of positive m can never be 0
    int high = m;

    while (low <= high) {

        int mid = low + (high - low) / 2;
        long long val = 1;

        // Calculate mid^n safely
        for (int i = 0; i < n; i++) {
            val *= mid;

            // If value exceeds m, no need to continue
            // Example: m=27, mid=4 → 4^3=64 (>27)
            if (val > m) break;
        }

        if (val == m) {
            return mid;         // exact nth root found
        }
        else if (val > m) {
            high = mid - 1;     // search left
        }
        else {
            low = mid + 1;      // search right
        }
    }

    return -1;  // no integer nth root exists
}
