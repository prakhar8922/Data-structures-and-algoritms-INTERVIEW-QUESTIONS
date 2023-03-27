// 49. Group Anagrams
// Medium
// 14.7K
// 427
// Companies
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

class Solution
{
public:
    string sortStr(string str)
    {
        int ch[26] = {0};
        // Initialize an array of 26 integers to keep track of the count of each character (a-z) in the string
        for (char c : str)
        {
            ch[c - 'a']++;
        }
        string temp;
        // Initialize a temporary string to hold the sorted characters
        for (int c = 0; c < 26; c++)
        {

            temp += string(ch[c], c + 'a');
            // Append the corresponding character to the temporary string ch[c] times
        }
        return temp;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (auto str : strs)
        {

            mp[sortStr(str)].push_back(str);
            // Sort the current string using the sortStr function and add it to the corresponding group in the map
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};