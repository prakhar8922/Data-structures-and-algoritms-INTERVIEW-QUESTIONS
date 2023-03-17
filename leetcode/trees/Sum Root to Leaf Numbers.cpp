// 129. Sum Root to Leaf Numbers
// Medium
// 6K
// 98
// Companies
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

// Example 1:

// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:

// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.

class Solution
{
public:
    void func(TreeNode *root, int &ans, int &sum)
    {
        if (!root)
            return;
        sum = sum * 10 + root->val;
        if (!root->left and !root->right)
        {
            ans += sum;
            sum = (sum - root->val) / 10;
            return;
        }
        func(root->left, ans, sum);
        func(root->right, ans, sum);
        sum = (sum - root->val) / 10;
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0, sum = 0;
        func(root, ans, sum);
        return ans;
    }
};

// Time complexity:
// We visit each node exactly once, so the time complexity is O(n)O(n)O(n), where n is the number of nodes in the tree.
// Space complexity:
// The space complexity is O(h)O(h)O(h), where h is the height of the tree, due to the recursive calls on the function call stack. In the worst case, the tree is a skewed tree with a height of n, resulting in a space complexity of O(n)O(n)O(n). However, in the best case, the tree is a balanced tree with a height of log n, resulting in a space complexity of O(log n).

// # Definition for a binary tree node.
// # class TreeNode:
// #     def __init__(self, val=0, left=None, right=None):
// #         self.val = val
// #         self.left = left
// #         self.right = right
// class Solution:

//     def sumNumbers(self, root: Optional[TreeNode]) -> int:
//          def func(root, ans, sum):
//             if not root:
//                 return
//             sum = sum * 10 + root.val
//             if not root.left and not root.right:
//                 ans[0] += sum
//                 sum = (sum - root.val) // 10
//                 return
//             func(root.left, ans, sum)
//             func(root.right, ans, sum)
//             sum = (sum - root.val) // 10

//          if not root:
//             return 0
//          ans, sum = [0], 0
//          func(root, ans, sum)
//          return ans[0]
