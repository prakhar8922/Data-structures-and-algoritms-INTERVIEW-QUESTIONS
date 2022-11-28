// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

class Solution
{
public:
    int calculate(string s)
    {
        stack<pair<int, int>> st; // pair(prev_calc_val,sign before next '(')
        long long int sum = 0;
        int sign = 1;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                long long int num = 0;
                while (i < s.size() and isdigit(s[i]))
                {
                    num = (num * 10) + s[i] - '0';
                    i++;
                }
                i--; // for loop also increase i , so if we don't decrease i here a sign will be skipped
                sum += (num * sign);
                sign = +1;
            }
            else if (ch == '(')
            {
                // Saving current state of (sum , sign) in stack
                st.push({sum, sign});
                // Reseting sum and sign for inner bracket calculation
                sum = 0;
                sign = +1;
            }
            else if (ch == ')')
            {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }
            else if (ch == '-')
            {
                sign = (-1 * sign);
            }
        }
        return sum;
    }
};
