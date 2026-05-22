/*
===========================================================
PROBLEM: Word Search (Leetcode 79)  (med-hard)
https://leetcode.com/problems/word-search/
===========================================================

Given:
- A 2D board of characters
- A word

Return true if the word exists in the grid.

Rules:
- Letters must be connected horizontally or vertically
- Same cell cannot be used twice

-----------------------------------------------------------
APPROACH: DFS + Backtracking
-----------------------------------------------------------

1. Start DFS from every cell.
2. If current character matches:
      - mark cell visited
      - explore 4 directions
3. If complete word matched:
      return true
4. Restore cell while backtracking.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

O(rows * cols * 4^L)

L = word length

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(L)

Recursion stack depth.

===========================================================
*/

class Solution {
public:

    bool dfs(int row,
             int col,
             int index,
             vector<vector<char>>& board,
             string& word) {

        // entire word matched
        if (index == word.size()) {
            return true;
        }

        // invalid cases
        if (row < 0 ||
            col < 0 ||
            row >= board.size() ||
            col >= board[0].size() ||
            board[row][col] != word[index]) {

            return false;
        }

        // store original character
        char ch = board[row][col];

        // mark visited
        board[row][col] = '#';

        // explore all 4 directions
        bool down  = dfs(row + 1, col, index + 1, board, word);

        bool right = dfs(row, col + 1, index + 1, board, word);

        bool up    = dfs(row - 1, col, index + 1, board, word);

        bool left  = dfs(row, col - 1, index + 1, board, word);

        // restore original character
        board[row][col] = ch;

        // if any direction returns true
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // try every cell as starting point
        for (int row = 0; row < rows; row++) {

            for (int col = 0; col < cols; col++) {

                if (dfs(row, col, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
