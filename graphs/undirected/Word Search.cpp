// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // checking for all positions
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(0, i, j, board, word))
                    return true;
        return false;
    }
    bool dfs(int index, int x, int y, vector<vector<char>> &board, string &word)
    {
        if (index == word.size()) // word exists in matrix
            return true;

        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or board[x][y] == '.') // boundary check + visited check
            return false;

        if (board[x][y] != word[index])
            return false;

        char temp = board[x][y];
        board[x][y] = '.'; // marking it visited

        // Move in 4 directions[UP , DOWN , LEFT , RIGHT]
        if (dfs(index + 1, x - 1, y, board, word) or dfs(index + 1, x + 1, y, board, word) or dfs(index + 1, x, y - 1, board, word) or dfs(index + 1, x, y + 1, board, word))
            return true;

        board[x][y] = temp; // backtrack step
                            // We mark each cell as unvisited after we check all the adjacent possibilities because we might visit that cell again when we start traversing the matrix from a different source cell.
        return false;
    }
}