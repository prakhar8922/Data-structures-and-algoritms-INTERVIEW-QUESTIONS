// Some people(n) are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

// Example 1:

// Input: n = 5
// Output: 4
// Explanation: 1,2,3,4,5 -> 2,4 -> 4.

// Example 2:

// Input: n = 9
// Output: 8
// Explanation: 1,2,3,4,5,6,7,8,9
// ->2,4,6,8 -> 4,8 -> 8.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int nthPosition(long long int n)
    {
        long long num = (long long)log2(n);
        return pow(2, num);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthPosition(n) << endl;
    }
    return 0;
}