// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() > 3 ||
            // empty segment is not valid
            s.size() == 0 ||
            // if the first character is 0, we cannot have something like 0x, 0xx
            (s[0] == '0' && s.size() > 1) ||
            // segment is out of range
            stoi(s) > 255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        int n = s.size(); // [seg1].[seg2].[seg3].[seg4]
        for (int i = 1; i <= 3 and i < n; i++)
        { // 1st dot - we just need to run it 3 times at most
            for (int j = i + 1; j <= i + 3 and j < n; j++)
            { // we place the 2nd dot in a similar way
                for (int k = j + 1; k <= j + 3 and k < n; k++)
                { // we place the 3rd dot in a similar way
                    string s1 = s.substr(0, i),
                           s2 = s.substr(i, j - i),
                           s3 = s.substr(j, k - j),
                           s4 = s.substr(k);
                    if (isValid(s1) and isValid(s2) and isValid(s3) and isValid(s4))
                    {
                        ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return ans;
    }
};