// Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. Given a Binary Tree of size N, print all diagonal sums.

// For the following input tree, output should be 9, 19, 42.
// 9 is sum of 1, 3 and 5.
// 19 is sum of 2, 6, 4 and 7.
// 42 is sum of 9, 10, 11 and 12.

// DiagonalSum

// Example 1:

// Input:
//          4
//        /   \
//       1     3
//            /
//           3
// Output: 7 4
// Example 2:

// Input:
//            10
//          /    \
//         8      2
//        / \    /
//       3   5  2
// Output: 12 15 3

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
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
    Node *root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> diagonalSum(Node *root);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> res = diagonalSum(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/
vector<int> diagonalSum(Node *root)
{
    // Add your code here
    vector<int> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int sum = 0;
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            while (temp)
            {
                sum += temp->data;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        v.push_back(sum);
    }
    return v;
}
