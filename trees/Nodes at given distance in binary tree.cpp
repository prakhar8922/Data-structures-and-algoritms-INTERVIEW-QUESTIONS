
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/link for question
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000

class Solution
{
public:
    void markedParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        // used to mark the parent nodes of the given node
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent; // maps node->parent[node and its parent]
        markedParent(root, parent);
        unordered_map<TreeNode *, bool> visited; // maps if the node has been visited earlier or not
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int curr_lvl = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (curr_lvl++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left])
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right])
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent[curr] && !visited[parent[curr]])
                { // if the parent node of the curr node
                    // has not been visited till now and its not null then mark it true and push it
                    // into the queue.
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};

// solution if the int value of target is given and not the ptr to target in the question(gfg)
// class Solution
// {
// private:

// public:

//     vector <int> KDistanceNodes(Node* root, int target , int k)
//     {
//         Node* tar;
//         unordered_map<Node*,Node*> parent;//used to mark the parent nodes of the given node
//         //maps node->parent[node and its parent]
//         queue<Node*> q;
//         q.push(root);
//         while(!q.empty()) {
//             auto cur = q.front();
//             q.pop();
//             if(cur->left) {
//                 q.push(cur->left);
//                 parent[cur->left] = cur;
//             }
//             if(cur->right) {
//                 q.push(cur->right);
//                 parent[cur->right] = cur;
//             }
//             if(cur->data == target) tar = cur;
//         }
//         unordered_map<Node*,bool> vis;//maps if the node has been visited earlier or not

//         vis[tar] = true;
//         q.push(tar);
//         int c = 0;
//         while(!q.empty()) {
//             if(c==k) break;
//             c++;
//             int n = q.size();
//             for(int i = 0;i<n;i++) {
//                 auto cur = q.front();
//                 q.pop();
//                 if(cur->left && !vis[cur->left]) {
//                     q.push(cur->left);
//                     vis[cur->left] = true;
//                 }
//                 if(cur->right && !vis[cur->right]) {
//                     q.push(cur->right);
//                     vis[cur->right] = true;
//                 }
//                 if(parent[cur] && !vis[parent[cur]]) {//if the parent node of the curr node
//                     //has not been visited till now and its not null then mark it true and push it
//                     //into the queue.
//                     q.push(parent[cur]);
//                     vis[parent[cur]] = true;
//                 }
//             }
//         }
//         vector<int> res;
//         while(!q.empty()) {
//             res.push_back(q.front()->data);
//             q.pop();
//         }
//         sort(res.begin(),res.end());
//         return res;
//     }
// };