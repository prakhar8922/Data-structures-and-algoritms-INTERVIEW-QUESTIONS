// Given a number and its reverse. Find that number raised to the power of its own reverse.
// Note: As answers can be very large, print the result modulo 109 + 7.

// Example 1:

// Input:
// N = 2
// Output: 4
// Explanation: The reverse of 2 is 2
// and after raising power of 2 by 2
// we get 4 which gives remainder as
// 4 by dividing 1000000007.
// Example 2:

// Input:
// N = 12
// Output: 864354781
// Explanation: The reverse of 12 is 21
// and 1221 , when divided by 1000000007
// gives remainder as 864354781.
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this fucntion

    long long power(long long n, long long r)
    {

        if (r == 0)
            return 1;
        long long temp = power(n, r / 2);
        temp = (temp * temp) % mod;
        if (r % 2 == 0)
            return temp;
        else
            return (temp * n) % mod;
    }
};

//{ Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}