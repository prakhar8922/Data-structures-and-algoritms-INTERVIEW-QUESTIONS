

// User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

// Function to return a list containing the postorder traversal of the tree.
void postorder(Node *root, vector<int> &v)
{
    if (root != NULL)
    {
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->data);
    }
}
vector<int> postOrder(Node *root)
{
    vector<int> v;
    postorder(root, v);
    return v;
}