// https://practice.geeksforgeeks.org/problems/burning-tree/1?track=amazon-tree
// Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

// Example 1:

// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value
// 8 is set on fire.
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.
// Example 2:

// Input:
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      7
//   /    /
//  8    10
// Target Node = 10
// Output: 5

// Your Task:
// You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ N ≤ 104

class Solution
{
    int solve(Node *root, unordered_map<Node *, Node *> &ump, Node *&X)

    {

        unordered_map<Node *, int> visited;

        queue<Node *> qu;

        int ans = 0;

        qu.push(X);

        while (!qu.empty())

        {

            int size = qu.size();

            int flag = 0;

            for (int i = 0; i < size; i++)

            {

                Node *temp = qu.front();

                qu.pop();

                if (temp->left && !visited[temp->left])

                {
                    flag = 1;

                    qu.push(temp->left);

                    visited[temp->left] = 1;
                }

                if (temp->right && !visited[temp->right])

                {
                    flag = 1;

                    qu.push(temp->right);

                    visited[temp->right] = 1;
                }

                if (ump[temp] && !visited[ump[temp]])

                {
                    flag = 1;

                    qu.push(ump[temp]);

                    visited[ump[temp]] = 1;
                }
            }

            if (flag)

                ans++;
        }

        return ans;
    }

    Node *parent_store(Node *root, unordered_map<Node *, Node *> &ump, int &target)

    {

        queue<Node *> q;
        Node *res;

        q.push(root);

        while (!q.empty())

        {

            Node *temp = q.front();

            q.pop();

            if (temp->data == target)

                res = temp;

            if (temp->left)

            {

                ump[temp->left] = temp;

                q.push(temp->left);
            }

            if (temp->right)

            {

                ump[temp->right] = temp;

                q.push(temp->right);
            }
        }

        return res;
    }

public:
    int minTime(Node *root, int target)
    {
        // Your code goes here
        if (root == NULL)

            return 0;

        unordered_map<Node *, Node *> ump;

        Node *X = parent_store(root, ump, target);

        int ans = solve(root, ump, X);

        return ans;
    }
};