// 993. Cousins in Binary Tree
// Easy
// 3.5K
// 173
// Companies
// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

// Example 1:

// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:

// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:

// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 1 <= Node.val <= 100
// Each node has a unique value.
// x != y
// x and y are exist in the tree.
// Accepted
// 241.1K
// Submissions
// 441.1K
// Acceptance Rate
// 54.6%

class Solution
{
    int xdepth, ydepth, xparent, yparent;
    void depth(TreeNode *root, int x, int y, int height, int parent)
    {
        if (!root)
            return;
        if (root->val == x)
        {
            xdepth = height;
            xparent = parent;
            return;
        }
        if (root->val == y)
        {
            ydepth = height;
            yparent = parent;
            return;
        }
        depth(root->left, x, y, height + 1, root->val);
        depth(root->right, x, y, height + 1, root->val);
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root->val == x or root->val == y)
            return false;
        depth(root, x, y, 0, -1);
        if (xdepth == ydepth and xparent != yparent)
            return true;
        return false;
    }
};