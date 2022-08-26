//{ Driver Code Starts
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