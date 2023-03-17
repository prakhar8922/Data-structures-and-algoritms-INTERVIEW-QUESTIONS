// 2583. Kth Largest Sum in a Binary Tree
// Medium
// 111
// 3
// Companies
// You are given the root of a binary tree and a positive integer k.

// The level sum in the tree is the sum of the values of the nodes that are on the same level.

// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

// Note that two nodes are on the same level if they have the same distance from the root.

// Example 1:

// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.
// Example 2:

// Input: root = [1,2,null,3], k = 1
// Output: 3
// Explanation: The largest level sum is 3.

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= 106
// 1 <= k <= n

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long> pq;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            long long sum = 0;
            int n = q.size();
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            pq.push(sum);
        }
        if (pq.size() < k)
            return -1;
        k = k - 1;
        while (k--)
            pq.pop();
        return pq.top();
    }
};

// class Solution:
//     def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
//         q,ans=deque([root]),[]
//         while len(q)>0:
//             count=0
//             for i in range(len(q)):
//                 node=q.popleft()
//                 if node.left:q.append(node.left)
//                 if node.right:q.append(node.right)
//                 count+=node.val

//             ans.append(count)
//         return sorted(ans)[-k] if k<=len(ans) else -1
//         # The '[-k]' index returns the kth largest element from the end of the sorted list, since the list is sorted in ascending order. For example, if k is 1, it will return the largest element of the list, if k is 2, it will return the second-largest element of the list, and so on.