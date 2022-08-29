

// A(X) for positive integer X is the sum of factorials of its digits. For example, A(154) = 1! + 5! + 4!= 145.
// Given a number N, find the minimum number X such that A(X) = N. You have to return a list of digits (without leading zeros) which represent the number X.

// Example 1:

// Input: N = 40321
// Output: 18
// Explanation: A(18)=1!+ 8! =40321
// Note that A(80) and A(81) are also
// 40321, But 18 is the smallest
// number.
// Example 2:

// Input: N = 5040
// Output: 7
// Explanation: A(7) = 7! = 5040.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> FactDigit(int N)
    { // loop to store the factorial of all the numbers from 1 to 9
        vector<int> fact(10);
        fact[0] = 1;
        for (int i = 1; i < 10; i++)
        {
            fact[i] = i * fact[i - 1];
        }
        // loop to subtract the largest number from the given number
        vector<int> ans;
        for (int i = 9; i > 0; i--)
        {
            while (N >= fact[i])
            {
                ans.push_back(i);
                N -= fact[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.FactDigit(N);
        for (auto i : ans)
            cout << i;
        cout << "\n";
    }
    return 0;
}