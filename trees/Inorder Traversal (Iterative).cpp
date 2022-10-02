class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        // code here
        stack<Node *> st;
        Node *node = root;
        vector<int> ans;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};