/*

|--------------------------------------------------------------------------
| Problem     : Letter Combinations of a Phone Number
| Platform    : LeetCode 17
| https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/2008190762/
|
| Problem Statement:
| Given a string containing digits from 2-9 inclusive,
| return all possible letter combinations that the number
| could represent based on mobile keypad mapping.
|
| Example:
| Input  : "23"
| Output : ["ad","ae","af","bd","be","bf","cd","ce","cf"]
|--------------------------------------------------------------------------
| Approach:
|
| We use Backtracking / Recursion.
|
| Step-by-step:
|
| 1. Every digit maps to multiple characters.
|    Example:
|       2 -> abc
|       3 -> def
|
| 2. At each recursion level:
|      - Pick one character from current digit
|      - Add it into current path
|      - Move to next digit
|
| 3. When path length becomes equal to total digits:
|      -> One valid combination formed
|      -> Store answer
|
| 4. After recursion:
|      -> Remove last character
|      -> Try next character
|
| This is classic:
|      Choose -> Explore -> Undo
|--------------------------------------------------------------------------
| Time Complexity:
|    O(4^n * n)
|
|    4^n  -> maximum combinations
|    n    -> copying string into answer
|
| Space Complexity:
|    O(n)
|    recursion stack + path
|--------------------------------------------------------------------------
| Important Concepts:
|    - Backtracking
|    - Recursion Tree
|    - Pick / Unpick Pattern
|    - State Restoration
|--------------------------------------------------------------------------
*/

class Solution {
public:

    void solve(int index,
               string &digits,
               string &path,
               vector<string> &ans,
               vector<string> &mapping) {

        // Base Case:
        // All digits processed
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        // Current digit
        int number = digits[index] - '0';

        // Corresponding letters
        string letters = mapping[number];

        // Try every possible letter
        for (int i = 0; i < letters.size(); i++) {

            // Choose
            path.push_back(letters[i]);

            // Explore
            solve(index + 1, digits, path, ans, mapping);

            // Undo (Backtrack)
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // Edge Case
        if (digits.empty()) {
            return {};
        }

        vector<string> ans;

        // Phone keypad mapping
        vector<string> mapping = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string path = "";

        solve(0, digits, path, ans, mapping);

        return ans;
    }
};
