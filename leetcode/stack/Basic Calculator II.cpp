// 227. Basic Calculator II
// Medium
// 5.4K
// 694
// Companies
// Given a string s which represents an expression, evaluate this expression and return its value.

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.

class Solution
{
public:
    int calculate(string s)
    {
        s += '+'; // At the end, we encounter another '+' sign, this is to push the last curr value into the stack.
        stack<int> st;
        int curr = 0;
        long long ans = 0;
        char sign = '+'; // to store the previously encountered sign
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                curr = curr * 10 + (s[i] - '0');
            else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
            {
                if (sign == '+')
                    st.push(curr);
                else if (sign == '-')
                    st.push(-1 * curr);
                else if (sign == '*')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num * curr);
                }
                else if (sign == '/')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num / curr);
                }
                curr = 0;
                sign = s[i];
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};