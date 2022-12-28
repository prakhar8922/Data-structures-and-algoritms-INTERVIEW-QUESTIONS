/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *nextNode(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->nextNode(word[i]);
        }
        node->setEnd();
    }
    bool checkIfAllPrefixExists(string word)
    {
        Node *node = root;
        bool flag = true;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->nextNode(word[i]);
                flag = flag & node->isEnd();
            }
            else
            {
                return false;
            }
        }
        return flag;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie *obj = new Trie();
        for (auto it : words)
        {
            obj->insert(it);
        }
        string longest = "";
        for (auto it : words)
        {
            if (obj->checkIfAllPrefixExists(it))
            {
                if (it.size() > longest.size())
                {
                    longest = it;
                }
                else if (it.size() == longest.size() and it < longest)
                {
                    longest = it;
                }
            }
        }
        return longest;
    }
};
// @lc code=end
