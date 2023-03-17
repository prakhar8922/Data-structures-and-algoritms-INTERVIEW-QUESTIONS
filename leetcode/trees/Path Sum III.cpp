// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Example 1:

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3

// Constraints:

// The number of nodes in the tree is in the range [0, 1000].
// -109 <= Node.val <= 109
// -1000 <= targetSum <= 1000

class Solution
{
public:
    vector<int> arr; // Declare a vector to store the values of nodes in the path
    int paths = 0;
    void getpath(TreeNode *root, int tsum)
    {
        if (!root)
            return;
        arr.push_back(root->val);   // Add the value of the current node to the vector
        getpath(root->left, tsum);  // Recursively search the left subtree
        getpath(root->right, tsum); // Recursively search the right subtree
        long long tempsum = 0;      // Initialize a variable to hold the temporary sum of the path
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            tempsum += arr[i];
            if (tempsum == tsum)
                paths++; // If the temporary sum equals the target sum, increment the answer
        }
        arr.pop_back(); // Remove the last value from the vector
    }
    int pathSum(TreeNode *root, int tsum)
    {
        getpath(root, tsum);
        return paths;
    }
};
