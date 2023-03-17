// 427. Construct Quad Tree
// Medium
// 943
// 1.3K
// Companies
// Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

// Return the root of the Quad-Tree representing the grid.

// Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

// A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

// val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
// isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
// class Node {
//     public boolean val;
//     public boolean isLeaf;
//     public Node topLeft;
//     public Node topRight;
//     public Node bottomLeft;
//     public Node bottomRight;
// }
// We can construct a Quad-Tree from a two-dimensional area using the following steps:

// If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
// If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
// Recurse for each of the children with the proper sub-grid.

// If you want to know more about the Quad-Tree, you can refer to the wiki.

// Quad-Tree format:

// The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

// It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

// If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
// Explanation: The explanation of this example is shown below:
// Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.

// Example 2:

// Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
// Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
// Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
// The topLeft, bottomLeft and bottomRight each has the same value.
// The topRight have different values so we divide it into 4 sub-grids where each has the same value.
// Explanation is shown in the photo below:

// Constraints:

// n == grid.length == grid[i].length
// n == 2x where 0 <= x <= 6

/*
 Definition for a QuadTree node.
  bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
*/

class Solution
{
public:
    Node *recursive(vector<vector<int>> &grid, int x, int y, int length)
    {
        if (length == 1) // Return a leaf node if the matrix size is one
            return new Node(grid[x][y], true);

        Node *topLeft = recursive(grid, x, y, length / 2);
        Node *topRight = recursive(grid, x, y + length / 2, length / 2);
        Node *bottomLeft = recursive(grid, x + length / 2, y, length / 2);
        Node *bottomRight = recursive(grid, x + length / 2, y + length / 2, length / 2);

        // If the four returned nodes are leaf and have the same values
        // Return a leaf node with the same value.
        if (topLeft->isLeaf and topRight->isLeaf and bottomLeft->isLeaf and bottomRight->isLeaf and topLeft->val == topRight->val and topRight->val == bottomLeft->val and bottomLeft->val == bottomRight->val)
            return new Node(topLeft->val, true);

        // If the four nodes aren't identical, return non-leaf node with corresponding child pointers.
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node *construct(vector<vector<int>> &grid)
    {
        return recursive(grid, 0, 0, grid.size());
    }
};
