// Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

// Note: Here Leaf node is a node which is connected to exactly one different node.

// Example 1:

// Input:
//            3
//          /    \                          
//        4       5
//       /  \      
//     -10   4
// Output: 16
// Explanation:
// Maximum Sum lies between leaf node 4 and 5.
// 4 + 4 + 3 + 5 = 16.
// Example 2:

// Input:
//             -15
//          /      \                          
//         5         6
//       /  \       / \
//     -8    1     3   9
//    /  \              \
//   2   -3              0
//                      / \
//                     4  -1
//                        /
//                      10
// Output:  27
// Explanation:
// The maximum possible sum from one leaf node
// to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

// Your Task:
// You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)

// Constraints:
// 2  ≤  Number of nodes  ≤  104
// -103  ≤ Value of each node ≤ 103

class Solution
{
public:
    int solve(Node *root, int &res)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->data;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        if (root->left == NULL)
            return (root->data + r);
        if (root->right == NULL)
            return (root->data + l);
        int temp = max(l, r) + root->data;
        int ans = l + r + root->data;
        res = max(res, ans);

        return temp;
    }
    int maxPathSum(Node *root)
    {
        int res = INT_MIN;
        int x = solve(root, res);
        if (root->left == NULL || root->right == NULL)
            return max(res, x);

        return res;
    }
};