 /*

# 📌 Problem: Find Second Largest and Second Smallest Elements

https://www.naukri.com/code360/problems/second-largest-number_13762781

🧠 Approach:

1. Second Largest:

   * Track largest and second largest
   * If new element > largest:
     slargest = largest
     largest = element
   * Else if element is between largest and slargest:
     update slargest

2. Second Smallest:

   * Track smallest and second smallest
   * If new element < smallest:
     ssmallest = smallest
     smallest = element
   * Else if element is between smallest and ssmallest:
     update ssmallest

⏱️ Time Complexity:

* O(n) for both functions

💾 Space Complexity:

* O(1)

⚠️ Edge Cases:

* All elements same → no second largest/smallest
* Array size < 2 → invalid case
* Negative numbers → use INT_MIN / INT_MAX carefully

❌ Common Mistakes:

* Using wrong initial values
* Not handling duplicates properly
* Returning wrong default when no answer exists
  ============================================================
  */

#include <bits/stdc++.h>
using namespace std;

// 🔹 Function to find second largest element
int secondLargest(vector<int> &a, int n) {
int largest = a[0];
int slargest = INT_MIN;

```
for (int i = 1; i < n; i++) {
    if (a[i] > largest) {
        slargest = largest;
        largest = a[i];
    }
    else if (a[i] < largest && a[i] > slargest) {
        slargest = a[i];
    }
}

return slargest;
```

}

// 🔹 Function to find second smallest element
int secondSmallest(vector<int> &a, int n) {
int smallest = a[0];
int ssmallest = INT_MAX;

```
for (int i = 1; i < n; i++) {
    if (a[i] < smallest) {
        ssmallest = smallest;
        smallest = a[i];
    }
    else if (a[i] > smallest && a[i] < ssmallest) {
        ssmallest = a[i];
    }
}

return ssmallest;
```

}

// 🔹 Main function to return both values
vector<int> getSecondOrderElements(int n, vector<int> a) {
int slargest = secondLargest(a, n);
int ssmallest = secondSmallest(a, n);

```
return {slargest, ssmallest};
```

}

# /*

🧪 Example:
Input:  [5, 2, 8, 3, 1]
Output: [5, 2]

Second Largest  = 5
Second Smallest = 2
===================

*/
