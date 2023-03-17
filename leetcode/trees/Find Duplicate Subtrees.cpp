// 652. Find Duplicate Subtrees
// Medium
// 4.7K
// 385
// Companies
// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.

// Example 1:

// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]
// Example 2:

// Input: root = [2,1,1]
// Output: [[1]]
// Example 3:

// Input: root = [2,2,2,3,null,3,null]
// Output: [[2,3],[3]]

// Constraints:

// The number of the nodes in the tree will be in the range [1, 5000]
// -200 <= Node.val <= 200

class Solution
{
public:
    unordered_map<string, int> mp;
    string dfs(TreeNode *root, vector<TreeNode *> &ans)
    {
        // We can use a hash table to keep track of the frequency of each subtree, where the key is a string representation of the subtree's structure and node values. Once we find a subtree with a frequency of 2, we can add its root node to the result list.
        if (!root)
            return "NULL";
        string exp = to_string(root->val) + "," + dfs(root->left, ans) + "," + dfs(root->right, ans);
        mp[exp]++;
        if (mp[exp] == 2)
            ans.emplace_back(root);
        return exp;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> ans;
        dfs(root, ans);
        return ans;
    }
};