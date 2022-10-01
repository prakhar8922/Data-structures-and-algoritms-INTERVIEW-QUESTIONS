void preOrder(Node *root, vector<int> &v)
{
    if (root != NULL)
    {
        v.push_back(root->data);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
}
vector<int> preorder(Node *root)
{
    vector<int> v;
    preOrder(root, v);

    return v;
}