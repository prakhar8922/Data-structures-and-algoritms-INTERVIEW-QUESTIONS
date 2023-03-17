// You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
// nth root of m should be correct upto 6places

// Sample Input 1:
// 1
// 3 27
// Sample Output 1:
// 3.000000
// Explanation For Sample Input 1:
// 3rd Root of 27 is 3.000000, as (3.000000)^3 is equal to 27.
// Sample Input 2:
// 1
// 4 69
// Sample Output 2:
// 2.882121

#include <bits/stdc++.h>

double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}
double findNthRootOfM(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-7;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}