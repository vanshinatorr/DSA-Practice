# /*

📌 Problem: Stock Spanner
https://leetcode.com/problems/online-stock-span/

🧠 Problem Summary:
Design a class StockSpanner that processes daily stock prices.
For each price, return the "span":
→ Number of consecutive days (including today)
→ such that price <= today's price

---

💡 Intuition:

* Har element apna span lekar aata hai
* Smaller/equal elements useless hain → unhe hata do
* Unka span add karke direct jump karo

---

🚀 Approach (Monotonic Stack):

* Stack stores: {price, span}
* Maintain decreasing stack (top always greater)

Steps:

1. span = 1 (current day)
2. While stack.top().price <= current price:
   span += stack.top().span
   pop()
3. Push {price, span}
4. Return span

---

⚠️ Common Mistake:
❌ Wrong:
st.pop();
span += st.top().second;   // crash / wrong

✅ Correct:
span += st.top().second;
st.pop();

---

❓ Why NOT span += 1 ?
Because each element represents multiple days

Example:
{70,2} → means 70 + 60 already counted
So we add 2, not 1

---

📊 Dry Run Insight:
Example: [100, 80, 60, 70, 75]

When 75 comes:

* Pop {70,2} → span += 2
  → covers (70 + 60) in one step

---

⏱ Complexity:
Time: O(n) (each element pushed & popped once)
Space: O(n)

---

🎯 Pattern Recognition:

* Monotonic Decreasing Stack
* Same concept used in:
  → Next Greater Element
  → Largest Rectangle in Histogram
  → Sliding Window (related thinking)

---

🧠 Interview Line:
"Each element stores its span, allowing us to skip
multiple elements in O(1) amortized time."

---

# 💻 Code (C++)

*/

class StockSpanner {
public:
stack<pair<int, int>> st; // {price, span}

```
StockSpanner() {}

int next(int price) {
    int span = 1;

    while (!st.empty() && st.top().first <= price) {
        span += st.top().second; // reuse previous span
        st.pop();
    }

    st.push({price, span});
    return span;
}
```

};
