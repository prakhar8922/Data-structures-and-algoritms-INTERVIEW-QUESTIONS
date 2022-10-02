class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            ans.push_back(root->data);
            if (root->left)
                s.push(root->left);
            if (root->right)
                s.push(root->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
