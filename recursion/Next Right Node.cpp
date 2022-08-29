// Given a Binary tree and a key in the binary tree, find the node right to the given key. If there is no node on right side, then return a node with value -1.

// Example 1:

// Input:

//        10
//      /    \
//     2      6
//    / \      \
//   8   4      5
// and key = 2
// Output: 6
// Explanation: We can see in the above tree
// that the next right node of 2 is 6.
// Example 2:

// Input:
//       10
//     /     \
//    2       6
//   / \       \
//  8   4       5
// and key = 5
// Output: -1
// Explanation: We can see in the above tree
// that there's No next right node of 5.
// So, the output is -1.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
class Solution
{
public:
    Node *nextRight(Node *root, int key)
    {
        queue<Node *> q;
        if (root == NULL)
            return new Node(-1);
        q.push(root);
        while (!q.empty())
        {
            queue<Node *> q1;
            while (!q.empty())
            {
                Node *top = q.front(); // auto top=q.front();
                q.pop();
                if (top->data == key)
                {
                    if (q.empty())
                        return new Node(-1);
                    else
                        return q.front();
                }
                if (top->left)
                    q1.push(top->left);
                if (top->right)
                    q1.push(top->right);
            }
            q = q1;
        }
        return new Node(-1);
    }
};