// Given a BST and a number X, find floor of X.
// Note: floor(X) is a number that is either equal to X or is immediately smaller than X.

int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    int floor = -1;
    while (root)
    {
        if (root->val == x)
        {
            floor = root->val;
            return floor;
        }
        else if (root->val < x)
        {
            floor = root->val;
            root = root->right;
        }
        else
            root->left;
    }
    return floor;
}
