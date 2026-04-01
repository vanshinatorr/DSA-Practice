# /*

Problem: Trapping Rain Water
Approach: Two Pointer (Your Style)

---

🧠 Idea:

* Smaller height side decides water
* Maintain running leftMax & rightMax

---

⏱️ Complexity:
Time: O(n)
Space: O(1)

---

💡 Trick:
"Compare height → move smaller → update max → add water"
========================================================

*/

class Solution {
public:
int trap(vector<int>& height) {

```
    int left = 0; 
    int right = height.size() - 1; 
    int totalwater = 0;

    int leftmax = 0;   // store max till left
    int rightmax = 0;  // store max till right  

    while (left < right) {

        // decide which side to process
        if (height[left] <= height[right]) {
          
            // update leftmax OR trap water
            leftmax = max(height[left], leftmax);
            
            // water only if current < max
            totalwater += leftmax - height[left]; 
            
            left++; 
        }
        else {
           
            // update rightmax OR trap water
            rightmax = max(height[right], rightmax); 
            
            // water only if current < max
            totalwater += rightmax - height[right]; 
            
            right--; 
        }
    }

    return totalwater; 
}
```

};

# /*

🔁 QUICK REVISION (YOUR VERSION)

👉 compare: height[left] vs height[right]

👉 if left smaller:
use leftmax
water += leftmax - height[left]
left++

👉 else:
use rightmax
water += rightmax - height[right]
right--

👉 IMPORTANT:

* max always stores history
* water only when current < max

========================================
*/
