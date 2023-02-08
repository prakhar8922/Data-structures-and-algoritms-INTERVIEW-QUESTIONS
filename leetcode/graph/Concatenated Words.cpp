// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Example 2:

// Input: words = ["cat","dog","catdog"]
// Output: ["catdog"]

// Constraints:

// 1 <= words.length <= 104
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 105

class Solution
{
    unordered_set<string> s;
    unordered_map<string, bool> mp; // The hash map "mp" stores the results of previous calls to the function "isConcat", so it does not need to recalculate the result for the same word again.
private:
    bool isConcat(string word)
    {
        if (mp.find(word) != mp.end())
            return mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            //             //Both prefix and suffix are found in the hash set "s", or
            // The prefix is found in the hash set "s" and the suffix is a concatenated word.
            if ((s.find(prefix) != s.end() and s.find(suffix) != s.end()) or
                s.find(prefix) != s.end() and isConcat(suffix))
                return mp[word] = true;
        }
        return mp[word] = false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;
        for (auto it : words)
        {
            s.insert(it);
        }
        for (int i = 0; i < words.size(); i++)
        {
            if (isConcat(words[i]))
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};