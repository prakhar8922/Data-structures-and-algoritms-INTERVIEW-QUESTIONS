// 22. Generate Parentheses
// Medium
// 17.2K
// 696
// Companies
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

// 1 <= n <= 8'

class Solution
{
public:
    void func(vector<string> &ans, string s, int open, int closed, int n)
    {
        // If the number of opening and closing brackets equals n, we have a valid combination
        if (open == n && closed == n)
        {
            ans.push_back(s);
            return;
        }
        // If we haven't used all the opening brackets yet, add an opening bracket and call func recursively
        if (open < n)
            func(ans, s + '(', open + 1, closed, n);
        // If we have more closing brackets than opening brackets, add a closing bracket and call func recursively
        if (closed < open)
            func(ans, s + ')', open, closed + 1, n);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        func(ans, "", 0, 0, n);
        return ans;
    }
};