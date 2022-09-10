// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

// Example 1:

// Input : str = "abc"
// Output: a ab abc ac b bc c
// Explanation : There are 7 subsequences that
// can be formed from abc.
// Example 2:

// Input: str = "aa"
// Output: a a aa
// Explanation : There are 3 subsequences that
// can be formed from aa.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes S as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from S in lexicographically-sorted order.

// Expected Time Complexity: O(2n) where n is the length of the String
// Expected Space Complexity: O(n * 2n)

// Constraints:
// 1 <= Length of String <= 16
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> res;
        int n = s.size();
        // 1<<n =2^n
        for (int i = 0; i < (1 << n); i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                // check if the jth bit is set or not
                if (i & (1 << j))
                    temp += s[j];
            }
            if (temp.size())
                res.push_back(temp);
        }
        sort(res.begin(), res.end());
        return res;
    }
};