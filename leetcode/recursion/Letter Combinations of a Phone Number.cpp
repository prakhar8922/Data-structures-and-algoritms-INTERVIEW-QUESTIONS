// 17. Letter Combinations of a Phone Number
// Medium
// 14.3K
// 822
// Companies
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

class Solution
{
public:
    void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
    {

        if (index >= digit.length())
        {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = mapping[number];
        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string output;
        if (digits.length() == 0)
        {
            return ans;
        }
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

// class Solution:
//     def letterCombinations(self, digits: str) -> List[str]:
//         if len(digits) == 0:
//             return []
//         letters = { '2': ['a','b','c'],
//                     '3': ['d','e','f'],
//                     '4': ['g','h','i'],
//                     '5': ['j','k','l'],
//                     '6': ['m','n','o'],
//                     '7': ['p','q','r','s'],
//                     '8': ['t','u','v'],
//                     '9': ['w','x','y', 'z'] }
//         res = []
//         def backtrack(idx, curr):
//             if len(curr) == len(digits):
//                 res.append(curr)
//                 return
//             for ch in letters[digits[idx]]:
//                 backtrack(idx+1 , curr+ch)
//         backtrack(0, '')
//         return res
