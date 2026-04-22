# /*

# 📌 Problem: Check if Array is Sorted and Rotated

🧠 Approach:

* Traverse the array and count how many times the order breaks
* A break is when: nums[i] > nums[(i+1) % n]
* If breaks <= 1 → valid (sorted + rotated)
* Else → invalid

⏱️ Time Complexity:

* O(n)

💾 Space Complexity:

* O(1)

⚠️ Edge Cases:

* Single element → always true
* All elements same → true
* Already sorted → true
* Multiple breaks → false

❌ Common Mistakes:

* Forgetting circular check (last → first)
* Using () instead of [] for vector access
  ============================================================
  */

class Solution {
public:
bool check(vector<int>& nums) {
int n = nums.size();
int countBreaks = 0;

```
    for (int i = 0; i < n; i++) {
        // Check for break in order
        if (nums[i] > nums[(i + 1) % n]) {
            countBreaks++;
        }
    }

    // Valid if at most one break
    return countBreaks <= 1;
}
```

};
