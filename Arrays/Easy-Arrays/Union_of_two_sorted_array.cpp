

// Problem: Sorted Array (Union of Two Sorted Arrays)
// Approach: Two Pointers + Duplicate Skipping

/*
-------------------------------------------------------
Problem
https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=chatgpt.com
-------------------------------------------------------
Given two sorted arrays 'a' and 'b',
return their union in sorted order without duplicates.

Example:
a = [1,2,2,3]
b = [2,3,4]

Output:
[1,2,3,4]

-------------------------------------------------------
Approach
-------------------------------------------------------

We use TWO POINTERS:

i -> traverse array a
j -> traverse array b

Main idea:
1. Compare a[i] and b[j]
2. Smaller element answer me push karo
3. Equal ho to sirf ek baar push karo
4. Duplicate avoid karne ke liye:
   ans.back() check karte hain

-------------------------------------------------------
Important Continue Logic
-------------------------------------------------------

Ye part bahut important hai:

if (!ans.empty() && ans.back() == a[i]) {
    i++;
    continue;
}

continue ka matlab:
-> Current iteration wahi stop
-> Fresh next loop iteration start

WHY IMPORTANT?

Agar continue nahi lagaya:

1. i++ ho jayega
2. Fir niche ka comparison code bhi chalega
3. Possible hai:
   - i array ke bahar chala jaye
   - invalid index access ho
   - duplicate process ho jaye

continue safely current iteration ko terminate karta hai.

-------------------------------------------------------
Dry Run
-------------------------------------------------------

a = [1,2,2,3]
b = [2,3,4]

Initial:
i=0, j=0
ans=[]

1 < 2
push 1

ans=[1]

2 == 2
push 2 once

ans=[1,2]

Now a[i]=2 again

Duplicate found:
ans.back()==2

i++
continue

Current iteration yahi stop.

Fresh loop start.

-------------------------------------------------------
Time Complexity
-------------------------------------------------------
O(n + m)

-------------------------------------------------------
Space Complexity
-------------------------------------------------------
O(n + m)   // answer array
-------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {

    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;

    vector<int> ans;

    // Traverse both arrays using two pointers
    while (i < n && j < m) {

        // Skip duplicate from array a
        if (!ans.empty() && ans.back() == a[i]) {
            i++;
            continue;
        }

        // Skip duplicate from array b
        if (!ans.empty() && ans.back() == b[j]) {
            j++;
            continue;
        }

        // If a[i] smaller
        if (a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        }

        // If b[j] smaller
        else if (b[j] < a[i]) {
            ans.push_back(b[j]);
            j++;
        }

        // Equal elements
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    // Remaining elements of array a
    while (i < n) {

        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }

        i++;
    }

    // Remaining elements of array b
    while (j < m) {

        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }

        j++;
    }

    return ans;
}

/*
-------------------------------------------------------
Common Mistakes
-------------------------------------------------------

1. continue bhool jana
-> duplicate process ho sakta hai

2. ans.back() without ans.empty()
-> runtime error possible

3. Equal elements me dono pointers move na karna
-> infinite loop

4. Leftover arrays handle na karna
-> last elements miss ho jayenge

-------------------------------------------------------
Sample Input
-------------------------------------------------------
a = [1,2,2,3]
b = [2,3,4]

-------------------------------------------------------
Output
-------------------------------------------------------
1 2 3 4

-------------------------------------------------------
Git Commit Message
-------------------------------------------------------
Implemented union of two sorted arrays using two pointers
with duplicate handling and detailed continue logic explanation
-------------------------------------------------------
*/
