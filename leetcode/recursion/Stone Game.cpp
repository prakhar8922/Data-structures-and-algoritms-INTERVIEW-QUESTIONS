// 877. Stone Game
// Medium
// 2.7K
// 2.6K
// Companies
// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles[i]) is odd.
// Accepted
// 188.8K
// Submissions
// 270.5K
// Acceptance Rate
// 69.8%

class Solution
{
public:
    int func(int i, int j, vector<int> &piles, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int front = piles[i] + min(func(i + 2, j, piles, dp), func(i + 1, j - 1, piles, dp));
        // Alex takes (i)th pile than array became (i+1, j)
        //  now if Lee will take the (i+1)th pile then array became (i+2, j)
        //  and if Lee will take the (j)th pile then array became (i+1, j-1)
        //  => Lee is supposed to take the maxi among 2 choices then Alex will reamin with min of    these 2 choices

        int end = piles[j] + min(func(i + 1, j - 1, piles, dp), func(i, j - 2, piles, dp));
        // Alex takes (j)th pile than array became (i, j-1)
        //  now if Lee will take the (i)th pile then array became (i+1, j-1)
        //  and if Lee will take the (j-1)th pile then array became (i, j-2)
        //  => Lee is supposed to take the maxi among 2 choices then Alex will reamin with min of these 2 choices*
        int alice = max(front, end);
        return dp[i][j] = alice;
    }
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size(), i = 0;
        int j = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int alice = func(i, j, piles, dp);
        int sum = 0;
        accumulate(piles.begin(), piles.end(), sum);
        return alice > sum / 2;
    }
};