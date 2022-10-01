
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
* /

    class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> v;
    vector<int> inOrder(Node *root)
    {

        if (root != NULL)
        {
            inOrder(root->left);
            v.push_back(root->data);
            inOrder(root->right);
        }
        return v;
    }
};