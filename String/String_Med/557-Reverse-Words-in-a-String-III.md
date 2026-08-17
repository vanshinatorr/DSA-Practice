# Reverse Words in a String III — LC 557

https://leetcode.com/problems/reverse-words-in-a-string-iii/
**Pattern:** String + Two Pointers



## Code

```cpp
class Solution {
public:
    string reverseWords(string s) {

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            string word = "";

            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            ans += word;
            ans += ' ';
        }

        ans.pop_back();

        return ans;
    }
};
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

## Key Learning

**Word complete hone ke baad hi reverse karna hai.**

```text
Collect → Reverse → Add
```

## Common Mistakes

* `i++` bhoolna → infinite loop
* `i < s.size()` check na karna
* `reverse()` ko `while` ke andar laga dena
* `ans` ko loop ke andar declare karna
* Last ka extra space remove na karna (`pop_back()`)
