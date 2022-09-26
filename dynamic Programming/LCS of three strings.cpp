// Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

// Example 1:

// Input:
// A = "geeks", B = "geeksfor",
// C = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common
// subsequence with length 5.
// â€‹Example 2:

// Input:
// A = "abcd", B = "efgh", C = "ijkl"
// Output: 0
// Explanation: There's no common subsequence
// in all the strings.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

// Expected Time Complexity: O(n1*n2*n3).
// Expected Auxiliary Space: O(n1*n2*n3).

// Constraints:
// 1<=n1, n2, n3<=20

#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int LCSof3(string a, string b, string c, int n1, int n2, int n3)
{
    int dp[n1 + 1][n2 + 1][n3 + 1];
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
            for (int k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else
                {
                    if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1] && b[j - 1] == c[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
    }
    return dp[n1][n2][n3];
}