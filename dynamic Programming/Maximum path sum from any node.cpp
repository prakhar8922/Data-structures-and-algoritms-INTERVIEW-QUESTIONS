// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Example 1:

// Input:
//      10
//     /  \
//    2   -25
//   / \  /  \
//  20 1  3  4
// Output: 32
// Explanation: Path in the given tree goes
// like 10 , 2 , 20 which gives the max
// sum as 32.
// Example 2:

// Input:
//      10
//    /    \
//   2      5
//           \
//           -2
// Output: 17
// Explanation: Path in the given tree goes
// like 2 , 10 , 5 which gives the max sum
// as 17.
// Your Task:
// You don't need to take input or print anything. Your task is to complete the function findMaxSum() that takes root as input and returns max sum between any two nodes in the given Binary Tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 103
// 1 ≤ |Data on node| ≤ 104

class Solution
{
public:
    // Function to return maximum path sum from any node in a tree.
    int solve(Node *root, int &res)
    {
        if (root == nullptr)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(max(l, r) + root->data, root->data); // path sum passes through root and
        // the sum of root node may be greater than its left subtree or right subtree as
        // their sum maybe negative and root may be positive
        int ans = max(temp, l + r + root->data); // path sum does not passes through root node
        res = max(res, ans);
        return temp;
    }
    int findMaxSum(Node *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};