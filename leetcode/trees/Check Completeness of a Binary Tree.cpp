// 958. Check Completeness of a Binary Tree
// Medium
// 3.2K
// 39
// Companies
// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
// Example 2:

// Input: root = [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// 1 <= Node.val <= 1000

class Solution
{
public:
    // traverse the tree level by level from left to right and we come across a null node, all subsequent nodes in this traversal should be null as well (should not exist). The level-order traversal array of a complete binary tree will never have a null node in between non-null nodes.
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;
        bool nullfound = false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node == NULL)
            {
                nullfound = true;
            }
            else
            {
                if (nullfound == true)
                {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

// Here n is the number of nodes.

// Time complexity: O(n)

// Each queue operation in the BFS algorithm takes O(1) time, and a single node can only be pushed once, leading to O(n) operations for nnn nodes. Since we have directed edges, each edge can only be iterated once, resulting in O(e) operations total while visiting all nodes, where eee is the number of edges. Because the given graph is a tree, there are n−1n - 1n−1 edges, so O(n+e)=O(n)
// Space complexity: O(n)

// The last or second last level would have the most nodes (the last level can have multiple null nodes) in a complete binary tree. Because we are iterating by level, the BFS queue will be most crowded when all of the nodes from the last level (or second last level) are in the queue.
// Assume we have a complete binary tree with height hhh and a fully filled last level having 2h2^h2
// h
//   nodes. All the nodes at each level add up to 1+2+4+8+...+2h=n1 + 2 + 4 + 8 +... + 2^h = n1+2+4+8+...+2
// h
//  =n. This implies that 2h+1−1=n2^{h + 1} - 1 = n2
// h+1
//  −1=n, and thus 2h=(n+1)/22^h = (n + 1) / 22
// h
//  =(n+1)/2. Because the last level hhh has 2h2^h2
// h
//   nodes, the BFS queue will have (n+1)/2=O(n) elements in the worst-case scenario.