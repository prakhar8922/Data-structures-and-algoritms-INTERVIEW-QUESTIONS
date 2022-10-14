class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        Node *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            { // if left is null then print the val of root and traverse right
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right; // traverse prev ptr towards right most node of left subtree
                }
                if (prev->right == NULL)
                { // make a thread which will connect the rightmost node of left
                    // subtree to the curr node and then curr traverses left
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                { // erase the thread connecting prev to curr and print the curr data and then
                    // traverse right
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};