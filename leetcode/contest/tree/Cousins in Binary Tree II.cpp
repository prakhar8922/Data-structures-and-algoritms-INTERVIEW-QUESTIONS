// 2641. Cousins in Binary Tree II
// Medium
// 204
// 2
// Companies
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.

// Example 1:

// Input: root = [5,4,9,1,10,null,7]
// Output: [0,0,0,7,7,null,11]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 5 does not have any cousins so its sum is 0.
// - Node with value 4 does not have any cousins so its sum is 0.
// - Node with value 9 does not have any cousins so its sum is 0.
// - Node with value 1 has a cousin with value 7 so its sum is 7.
// - Node with value 10 has a cousin with value 7 so its sum is 7.
// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
// Example 2:

// Input: root = [3,1,2]
// Output: [0,0,0]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 3 does not have any cousins so its sum is 0.
// - Node with value 1 does not have any cousins so its sum is 0.
// - Node with value 2 does not have any cousins so its sum is 0.

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 104
// Accepted
// 8.2K
// Submissions
// 12.5K
// Acceptance Rate
// 65.8%

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        // Set root's value to 0
        root->val = 0;

        // Create a queue and add the root to it
        queue<TreeNode *> q;
        q.push(root);

        // Traverse the tree level by level
        while (!q.empty())
        {
            // Get the number of nodes in the current level and initialize the sum
            int n = q.size(), sum = 0;
            // Create a vector to hold the nodes in the current level
            vector<TreeNode *> temp;

            // Process each node in the current level
            while (n--)
            {
                // Get the front node from the queue
                auto node = q.front();
                q.pop();
                // Add the node to the vector
                temp.push_back(node);

                // Add the node's children to the queue and update the sum
                if (node->left)
                {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if (node->right)
                {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }

            // Update the values of each node in the current level
            for (auto node : temp)
            {
                // Calculate the new value for the node
                int tempsum = sum;
                if (node->left)
                {
                    tempsum -= node->left->val;
                }
                if (node->right)
                {
                    tempsum -= node->right->val;
                }
                // Update the node's value
                if (node->left)
                {
                    node->left->val = tempsum;
                }
                if (node->right)
                {
                    node->right->val = tempsum;
                }
            }
        }

        // Return the modified root
        return root;
    }
};