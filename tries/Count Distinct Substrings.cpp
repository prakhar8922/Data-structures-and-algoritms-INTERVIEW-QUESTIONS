// Given a string of alphabetic characters. Return the count of distinct substrings of the string(including the empty string) using the Trie data structure.

// Examples:

// Example 1:
// Input:
//  S1= “ababa”
// Output: Total number of distinct substrings : 10
// Explanation: All the substrings of the string are a, ab, aba, abab, ababa, b, ba, bab, baba, a, ab, aba, b, ba, a. Many of the substrings are duplicated. The distinct substrings are a, ab, aba, abab, ababa, b, ba, bab, baba. Total Count of the distinct substrings is 9 + 1(for empty string) = 10.

// Example 2:
// Input:
//  S1= “ccfdf”

// Output: Total number of distinct substrings : 14
// Explanation:
// All the substrings of the string are c, cc, ccf, ccfd, ccfdf, c, cf, cfd, cfdf, f, fd, fdf, d, df, f. Many of the substrings are duplicated. The distinct substrings are c, cc, ccf, ccfd, ccfdf, cf, cfd, cfdf, f, fd, fdf, d, df. Total Count of the distinct substrings is 13 + 1(for empty string) = 14.
struct Node
{
    /* data */
    Node *links[26];

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *nextNode(char ch)
    {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(s[j]))
            {
                node->put(s[j], new Node());
                count++;
            }
            node = node->nextNode(s[j]);
        }
    }
    return count + 1;
}