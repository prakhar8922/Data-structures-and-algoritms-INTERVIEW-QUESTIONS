// Implement a data structure ”TRIE” from scratch. Complete some functions.

// 1) Trie(): Initialize the object of this “TRIE” data structure.

// 2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.

// 3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.

// 4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// 5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.

// Note:

// 1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

// 2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.

// Example:
// Input:
// 1
// 6
// insert samsung
// insert samsung
// insert  vivo
// erase vivo
// countWordsEqualTo samsung
// countWordsStartingWith vi
// Output:
// 2
// 0

// Explanation:

// Insert “samsung”: we are going to insert the word “samsung” into the “TRIE”.
// Insert “samsung”: we are going to insert the word “samsung” again into the “TRIE”.
// Insert “vivo”: we are going to insert the word “vivo” into the “TRIE”.
// Erase “vivo”: we are going to delete the word “vivo” from the “TRIE”.
// countWordsEqualTo “samsung”: There are two instances of “samsung” is present in “TRIE”.
// countWordsStartWith “vi”:There is not a single word in the “TRIE” that starts from the prefix “vi”.

#include <bits/stdc++.h>

using namespace std;
struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // get the node for traversing
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // inserts the char into node
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
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
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};