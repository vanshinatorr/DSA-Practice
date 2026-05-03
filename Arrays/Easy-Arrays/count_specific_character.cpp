
/*
-------------------------------------------------------
🧩 Problem:
Count occurrences of a specific character in a string.

This question appeared in AMCAT exam (not from Striver Sheet).

Given:
- A string `data`
- A character `coder`

Return:
- Number of times `coder` appears in `data`


Input:
haveagoodday
a
Output:
3

Input:
hello world
o
Output:
2

-------------------------------------------------------

💡 Approach:
- Traverse the string once
- Compare each character with target character
- Increment counter when match found

-------------------------------------------------------

⏱️ Complexity:
- Time: O(n)
- Space: O(1)

-------------------------------------------------------

⚠️ Common Mistakes:
- Using hashmap (overkill)
- Using wrong data types (int instead of char)
- Not handling empty string

-------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;



// code 
int countChar(string data, char coder) {
    int count = 0;

    for (char ch : data) {
        if (ch == coder) {
            count++;
        }
    }

    return count;
}
//



int main() {
    string data;
    getline(cin, data);

    char coder;
    cin >> coder;

    int result = countChar(data, coder);
    cout << result;

    return 0;
}
