// Given a BST and a number X, find floor of X.
// Note: floor(X) is a number that is either equal to X or is immediately smaller than X.

int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    int ans = -1;
    while (root)
    {
        if (root->val <= x)
        {
            ans = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}
