/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "NULL,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> q;
        string s;
        for (char c : data)
        {
            if (c == ',')
            {
                q.push(s);
                s = "";
                continue;
            }
            s += c;
        }
        if (s.size() != 0)
            q.push(s);
        return deserialize_helper(q);
    }
    TreeNode *deserialize_helper(queue<string> &q)
    {
        string s = q.front();
        q.pop();
        if (s == "NULL")
            return NULL;
        TreeNode *root = new TreeNode(stoi(s)); // converts string into int

        root->left = deserialize_helper(q);
        root->right = deserialize_helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
