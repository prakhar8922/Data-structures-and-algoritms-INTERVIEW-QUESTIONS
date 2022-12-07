// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]

// Constraints:

// 1 <= n <= 9

class Solution
{
private:
    void func(int col, int n, vector<vector<string>> &ans, vector<string> &board,
              vector<int> &leftrow, vector<int> &upperdiagnol, vector<int> &lowerdiagnol)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 and lowerdiagnol[row + col] == 0 and // if row+col=0 it means there is already a queen placed on its lowerdiagnal and if n-1+col-row=0 then queen is already placed at upper diagnol
                upperdiagnol[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagnol[row + col] = 1;
                upperdiagnol[n - 1 + col - row] = 1;
                func(col + 1, n, ans, board, leftrow, upperdiagnol, lowerdiagnol);

                board[row][col] = '.'; // for taking out the inserted 'Q' from the board(backtracking)
                leftrow[row] = 0;
                lowerdiagnol[row + col] = 0;
                upperdiagnol[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperdiagnol(2 * n - 1, 0), lowerdiagnol(2 * n - 1, 0); // we will 2*n-1 vector size to store all the sum for row and col
        func(0, n, ans, board, leftrow, upperdiagnol, lowerdiagnol);
        return ans;
    }
};