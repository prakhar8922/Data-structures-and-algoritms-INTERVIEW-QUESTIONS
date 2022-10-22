/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildBst(vector<int> &v, int &i, int ub)
    { // ub=upper bound
        if (i == v.size() || v[i] > ub)
            return NULL;
        TreeNode *root = new TreeNode(v[i++]);
        root->left = buildBst(v, i, root->val);
        root->right = buildBst(v, i, ub);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return buildBst(preorder, i, INT_MAX);
    }
};
// @lc code=end
