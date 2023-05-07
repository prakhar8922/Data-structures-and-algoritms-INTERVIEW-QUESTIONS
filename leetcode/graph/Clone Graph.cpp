// 133. Clone Graph
// Medium
// 7.8K
// 3.2K
// Companies
// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

// Example 1:

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:

// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.

// Constraints:

// The number of nodes in the graph is in the range [0, 100].
// 1 <= Node.val <= 100
// Node.val is unique for each node.
// There are no repeated edges and no self-loops in the graph.
// The Graph is connected and all nodes can be visited starting from the given node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *dfs(Node *curr, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> vis;
        // Clone the current node and add it to the map
        Node *clone = new Node(curr->val);
        mp[curr] = clone;
        // For each neighbor of the current node
        for (auto it : curr->neighbors)
        {
            // If the neighbor is already visited, clone its clone
            if (mp.find(it) != mp.end())
            {
                vis.push_back(mp[it]);
            }
            // If the neighbor is not yet visited, clone it and add it to the visited list
            else
                vis.push_back(dfs(it, mp));
        }
        // Assign the cloned neighbors to the clone of the current node
        clone->neighbors = vis;
        // Return the clone of the current node
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        // An unordered map to keep track of visited nodes and their clones
        unordered_map<Node *, Node *> mp;
        // If the input node is NULL, return NULL
        if (!node)
            return NULL;
        // If the input node has no neighbors, return its clone
        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        // Otherwise, perform DFS to clone the graph
        return dfs(node, mp);
    }
};