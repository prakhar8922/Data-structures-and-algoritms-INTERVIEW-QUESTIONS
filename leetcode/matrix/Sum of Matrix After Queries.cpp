// 2718. Sum of Matrix After Queries
// Medium
// 418
// 17
// Companies
// You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].

// Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:

// if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
// if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
// Return the sum of integers in the matrix after all queries are applied.

// Example 1:

// Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
// Output: 23
// Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23.
// Example 2:

// Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
// Output: 17
// Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.

// Constraints:

// 1 <= n <= 104
// 1 <= queries.length <= 5 * 104
// queries[i].length == 3
// 0 <= typei <= 1
// 0 <= indexi < n
// 0 <= vali <= 105
// Accepted
// 12.3K
// Submissions
// 44.9K
// Acceptance Rate
// 27.3%

class Solution
{
public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries)
    {
        // The queries which will come later will have a greater impact on final sum because it will overwrite any cell that was filled/not-filled before. Therefore, we can try to make sum by traversing in reverse direction of queries.
        int rowSeenCount = 0, colSeenCount = 0;
        vector<bool> rowSeen(n), colSeen(n);
        long long sum = 0;
        for (int i = queries.size() - 1; i >= 0; i--)
        {
            int type = queries[i][0], index = queries[i][1], val = queries[i][2];
            if (type == 0 and !rowSeen[index])
            {
                rowSeenCount++;
                rowSeen[index] = true;
                sum += (long long)(n - colSeenCount) * val;
            }
            if (type == 1 and !colSeen[index])
            {
                colSeenCount++;
                colSeen[index] = true;
                sum += (long long)(n - rowSeenCount) * val;
            }
        }
        return sum;
    }
};