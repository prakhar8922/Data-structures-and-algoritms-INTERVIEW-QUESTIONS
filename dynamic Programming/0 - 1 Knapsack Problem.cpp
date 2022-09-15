// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0
// Your Task:
// Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

// Expected Time Complexity: O(N*W).
// Expected Auxiliary Space: O(N*W)

// Constraints:
// 1 ≤ N ≤ 1000
// 1 ≤ W ≤ 1000
// 1 ≤ wt[i] ≤ 1000
// 1 ≤ v[i] ≤ 1000

//  Recursive solution with TC-2^n
// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n)
//     {
//       if(n==0||W==0)
//       return 0;

//       if(wt[n-1]<=W)
//       return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),
//       knapSack(W,wt,val,n-1));
//       else if(wt[n-1]>W)
//       return  knapSack(W,wt,val,n-1);
//     }
// };

// dynamic programming solution
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// int static mat[1002][1002];
// int solve(int W, int wt[], int val[], int n)
// {
//     if (W == 0 || n == 0)
//         return 0;
//     if (mat[n][W] != -1)
//         return mat[n][W];
//     if (wt[n - 1] <= W)
//         return mat[n][W] = max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1), solve(W, wt, val, n - 1));
//     else if (wt[n - 1] > W)
//         return mat[n][W] = solve(W, wt, val, n - 1);
// }
// class Solution
// {
//     // memset(mat,-1,sizeof(mat[0][0])*1002*1002);
// public:
//     // Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n)
//     {
//         // Your code here
//         memset(mat, -1, sizeof(mat));
//         int ans;
//         ans = solve(W, wt, val, n);
//         return ans;
//     }
// };
// Bottom down approach
// where i->n and j->W
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        int i, j;
        int K[n + 1][W + 1];

        // building table K[][] in bottom up manner.
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= W; j++)
            {
                // base case
                if (i == 0 || j == 0)
                    K[i][j] = 0;

                // if weight of current item is more than Knapsack capacity W
                // then this item cannot be included in the optimal solution.
                else if (wt[i - 1] <= j)
                    K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);

                // else updating K[i][w] as K[i-1][w].
                else
                    K[i][j] = K[i - 1][j];
            }
        }
        // returning the result.
        return K[n][W];
    }
};