// 211. Design Add and Search Words Data Structure
// Medium
// 6.7K
// 382
// Companies
// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 3 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

class TrieNode
{
public:
    bool isCompleteWord;
    TrieNode *children[26];

    TrieNode()
    {
        isCompleteWord = false;                // when the word is complete (mark that node as true)
        memset(children, 0, sizeof(children)); // for 26 possible Childrens (for next letter)
    }
};

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        // Initialize a TrieNode pointer named node and set it to the root of the trie
        TrieNode *node = root;
        // Iterate over each character 'ch' in the input string 'word'
        for (char ch : word)
        {
            // Calculate the index of the character in the trie array by subtracting 'a' from it
            int idx = ch - 'a';
            // If the child node corresponding to the index is NULL, create a new TrieNode and set it as the child
            if (node->children[idx] == NULL)
            {
                node->children[idx] = new TrieNode();
            }
            // Move the current node pointer to the child node corresponding to the index
            node = node->children[idx];
        }

        // After the loop, mark the last node as a complete word by setting its isCompleteWord flag to true
        node->isCompleteWord = true;
    }

    bool search(string word)
    {
        return searchHelper(word, root);
    }

    // Define a recursive function named searchHelper that takes in a string and a TrieNode pointer
    bool searchHelper(string word, TrieNode *node)
    {

        // Iterate over each character 'ch' in the input string 'word'
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            // If the character is a '.', we need to search all possible child nodes
            if (ch == '.')
            {

                // Iterate over each child node of the current node
                for (auto c : node->children)
                {

                    // If a child node exists and searching from the next character onwards returns true,
                    // then return true (as we have found a match)
                    if (c && searchHelper(word.substr(i + 1), c))
                    {
                        return true;
                    }
                }

                // If we have iterated over all child nodes and not found a match, return false
                return false;
            }

            // Calculate the index of the character in the trie array by subtracting 'a' from it
            int idx = ch - 'a';

            // If the child node corresponding to the index is NULL, the word does not exist in the trie
            if (node->children[idx] == NULL)
            {
                return false;
            }

            // Move the current node pointer to the child node corresponding to the index
            node = node->children[idx];
        }

        // If we have iterated over all characters in the input string and reached a TrieNode that represents
        // the end of a word, then return true (as the word exists in the trie). Otherwise, return false.
        return node->isCompleteWord;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */