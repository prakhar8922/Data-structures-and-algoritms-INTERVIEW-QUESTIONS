/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        // Both p and q are on the left
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        // Both p and q are on the right
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        // 1. p and q are on different sides
        // OR
        // 2. Either p or q is equal to the root
        return root;
    }
};
// @lc code=end
