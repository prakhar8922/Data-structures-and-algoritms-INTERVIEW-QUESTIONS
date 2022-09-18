

// We have S1 + S2 = Array_Sum;

// and          S1 - S2 = d;

// which implies S1 = (Array_Sum + d) / 2;

#include <bits/stdc++.h>
int perfectSum(vector<int> &arr, int n, int sum)
{
    int t[n + 1][sum + 1];
    int mod = (int)1e9 + 7;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
            if (i > 0 && j >= 0)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % mod;
                }
                else
                {
                    t[i][j] = (t[i - 1][j]) % mod;
                }
            }
        }
    }
    return t[n][sum] % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (int x : arr)
        sum += x;
    //     i) sum can't be fraction, so Array_Sum + d should be even
    // ii) difference can't be greater than Array_Sum

    if (d > sum || (sum + d) % 2)
        return 0;
    return perfectSum(arr, n, (sum + d) / 2);
}
