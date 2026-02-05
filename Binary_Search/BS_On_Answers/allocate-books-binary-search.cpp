/* <!--
# Allocate Books

## Problem
Given books with pages and m students:

- Each student gets ≥ 1 book
- Books assigned contiguously
- Minimize the maximum pages assigned to any student

Return that minimum value, or -1 if allocation is impossible.

---

## Intuition

We want to minimize the *maximum pages per student*.

Observation:

Small limit → more students needed  
Large limit → fewer students needed  

This monotonic behavior allows Binary Search on answer.

---

## Approach (Binary Search)

1. If students > books → impossible → return -1

2. Search range:
   low = max(arr)
   high = sum(arr)

3. For each mid:
   greedily assign books without exceeding mid

4. Count students needed.

5. If students ≤ m:
   mid valid → try smaller

6. Else:
   increase limit

---

## Greedy Allocation Logic

Keep adding books to a student until limit exceeded → assign new student.

---

## Example Insight

Allocation:
12, 34, 67 | 90

Student pages:
113 and 90

Maximum = 113

We want the allocation where this maximum is minimum.

---

## Complexity

Time: O(n log(sum(arr)))  
Space: O(1)

Key learning:
Binary search on answer + greedy partitioning.
-->
*/ 
## Code (C++)

```cpp
int findPages(vector<int>& arr, int n, int m) {

    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = 0;

    for (int x : arr)
        high += x;

    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int students = 1;
        int pages = 0;

        for (int i = 0; i < n; i++) {

            if (pages + arr[i] <= mid) {
                pages += arr[i];
            }
            else {
                students++;
                pages = arr[i];
            }
        }

        if (students <= m) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}
```
