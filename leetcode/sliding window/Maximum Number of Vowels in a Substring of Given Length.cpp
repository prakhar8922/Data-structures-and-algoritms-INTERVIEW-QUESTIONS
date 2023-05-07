// 1456. Maximum Number of Vowels in a Substring of Given Length
// Medium
// 1.8K
// 64
// Companies
// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length
// Accepted
// 89.6K
// Submissions
// 149.6K
// Acceptance Rate
// 59.9%

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        unordered_map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        int ans = 0, i = 0, j = 0, vowels = 0, n = s.size();
        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
                vowels++;
            if (j - i + 1 == k)
            {
                ans = max(ans, vowels);
                if (mp.find(s[i]) != mp.end())
                    vowels--;
                i++;
            }
            j++;
        }
        return ans;
    }
};