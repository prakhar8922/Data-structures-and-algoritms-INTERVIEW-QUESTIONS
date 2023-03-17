// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" or num2 == "0")
            return "0";
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(size(num1) + size(num2), 0);
        for (int i = size(num1) - 1; i >= 0; i--)
        {
            for (int j = size(num2) - 1; j >= 0; j--)
            {
                // The line num[i + j] += num[i + j + 1] / 10; adds any carry from the units digit to the corresponding tens digit.
                // Finally, the line num[i + j + 1] %= 10; ensures that only the units digit is stored in num[i+j+1], while any carry is added to num[i+j].

                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // for the last digit in num1 and num2, let's say 123 and 456 are at the 2nd index (in a 0 indexed array), so i == j ==2, that means i+j = 4, but in a six digit array, we need to put the value at the fifth position (0 indexed). so it is taken as [i+j+1].
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        // skip leading 0's
        int i = 0;
        while (i < size(num) and num[i] == 0)
        {
            i++;
        }
        string ans = "";
        while (i < num.size())
            ans.push_back(num[i++] + '0');
        return ans;
    }
};
