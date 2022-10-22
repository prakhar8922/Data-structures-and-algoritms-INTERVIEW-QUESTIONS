/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool bst(TreeNode *root, long minval, long maxval)
    {
        if (!root)
            return true;
        if (root->val >= maxval || root->val <= minval)
            return false;
        return bst(root->left, minval, root->val) &&
               bst(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode *root)
    {
        return bst(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end
