// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// Example 1:

// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7
// Example 2:

// Input:
//            7
//         /     \
//        9       7
//      /  \     /
//     8    8   6
//    /  \
//   10   9
// Output:
// 7 7 9 8 8 6 9 10

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 104

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;
        if (root == NULL)
            return ans;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                int index = leftToRight ? i : n - i - 1; // if lefttoright is true then at index i
                // else at index n-i-1
                temp[index] = curr->data;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            leftToRight = !leftToRight;
            for (auto x : temp)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
