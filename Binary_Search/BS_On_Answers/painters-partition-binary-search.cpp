/* <!--
# Painter’s Partition Problem

## Problem
We have A painters and boards with lengths C[i].

Rules:
- Each painter paints contiguous boards
- Boards cannot be split
- Each unit board takes B time

Goal:
Minimize the maximum time any painter spends.

Return result modulo 10000003.

---

## Intuition

We want to minimize the maximum workload per painter.

Observation:

Small time limit → more painters needed  
Large time limit → fewer painters needed  

Monotonic behavior → Binary Search on answer.

This is the same pattern as:
- Allocate Books
- Split Array Largest Sum

---

## Approach (Binary Search)

1. Search range:
   low = max(C)
   high = sum(C)

2. For each mid:
   greedily assign boards to painters

3. Count painters needed.

4. If painters ≤ A:
   mid valid → try smaller

5. Else:
   increase mid

Final time = mid × B

Return modulo result.

---

## Greedy Logic

Add board lengths until limit exceeded → assign next painter.

---

## Complexity

Time: O(n log(sum(C)))  
Space: O(1)

Key learning:
Binary search on answer + greedy partition.
-->
*/
## Code (C++)

```cpp
int paint(int A, int B, vector<int> &C) {

    const int MOD = 10000003;

    long long low = *max_element(C.begin(), C.end());
    long long high = 0;

    for (int x : C)
        high += x;

    long long ans = high;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        int painters = 1;
        long long work = 0;

        for (int x : C) {

            if (work + x <= mid) {
                work += x;
            }
            else {
                painters++;
                work = x;
            }
        }

        if (painters <= A) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    long long result = (ans % MOD * B % MOD) % MOD;

    return (int)result;
}

