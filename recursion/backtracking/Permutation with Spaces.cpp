// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

// Example 1:

// Input:
// S = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
// Explanation:
// ABC
// AB C
// A BC
// A B C
// These are the possible combination of "ABC".

// Example 2:

// Input:
// S = "AB"
// Output: (A B)(AB)

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

// Expected Time Complexity: O(2^n)
// Expected Auxiliary Space: O(1)

// CONSTRAINTS:
// 1 <= |S| < 10
// S only contains lowercase and Uppercase English letters.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<string> &ans, string ipt, string otp)
    {
        if (ipt.size() == 0)
        {
            ans.push_back(otp);
            return;
        }
        string opt1 = otp;
        string opt2 = otp;
        opt1.push_back(' ');
        opt1.push_back(ipt[0]);
        opt2.push_back(ipt[0]);
        ipt.erase(ipt.begin() + 0);
        solve(ans, ipt, opt1);
        solve(ans, ipt, opt2);
    }
    vector<string> permutation(string s)
    {
        vector<string> ans;
        string otp = "";
        otp.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(ans, s, otp);
        return ans;
    }
};