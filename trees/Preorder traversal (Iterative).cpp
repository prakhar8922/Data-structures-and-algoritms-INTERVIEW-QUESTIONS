class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        // code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            if (root->right != NULL)
                st.push(root->right);

            if (root->left != NULL)
                st.push(root->left);
        }
        return ans;
    }
};
