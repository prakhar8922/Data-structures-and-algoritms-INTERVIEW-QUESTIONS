// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.

class Solution
{
private:
    void func(int idx, string s, vector<string> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(s);
            return;
        }
        if (isalpha(s[idx]))
        { // if the scanned char is alphabet
            s[idx] = tolower(s[idx]);
            func(idx + 1, s, ans);
            s[idx] = toupper(s[idx]);
            func(idx + 1, s, ans);
        }
        else
        { // if the scanned character is digit
            func(idx + 1, s, ans);
        }
    }

public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        func(0, s, ans);
        return ans;
    }
};