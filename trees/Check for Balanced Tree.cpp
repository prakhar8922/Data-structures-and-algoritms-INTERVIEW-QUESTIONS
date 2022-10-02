class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    bool flag = true;
    int height(Node *root)
    {
        if (root == NULL)
            return 0;
        int lt = height(root->left);
        int rt = height(root->right);
        if (abs(lt - rt) > 1)
            flag = false;
        return 1 + max(lt, rt);
    }

    bool isBalanced(Node *root)
    {

        int h = height(root);
        return flag;
    }
};