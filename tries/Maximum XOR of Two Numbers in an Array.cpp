// You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’ of sizes N and M respectively. Find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation. Maximum XOR of Two Numbers in an Array.

// Examples:

// Example 1:

// Input: N=2, M=3
//        arr1 = [6, 8]
//        arr2 = [7, 8, 2]

// Output: 15

// Explanation: Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15

// Example 2:

// Input: N=2, M=2
//        arr1 = [1, 2
// ]
//        arr2 = [1, 1]

// Output: 3

// Explanation: 3 is the maximum possible xor among all possible pairs.

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *nextNode(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            /* code */
            int bit = (num >> i) & 1; // finding if the bit is 1 or 0
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->nextNode(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {                               // opposite bit
                maxNum = maxNum | (1 << i); // left shiting the opposite bit and using bitwise or with maxNum so as to get the ith index as 1
                node = node->nextNode(!bit);
            }
            else
                node = node->nextNode(bit);
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (auto it : arr1)
    {
        trie.insert(it);
    }
    int mx = 0;
    for (auto it : arr2)
    {
        mx = max(mx, trie.findMax(it));
    }
    return mx;
}