// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.

// Example 1:

// Input:
// N = 4
// inorder[] = {1 6 8 7}
// preorder[] = {1 6 7 8}
// Output: 8 7 6 1
// Example 2:

// Input:
// N = 6
// inorder[] = {3 1 4 0 5 2}
// preorder[] = {0 1 3 4 2 5}
// Output: 3 4 1 5 2 0
// Explanation: The tree will look like
//        0
//     /     \
//    1       2
//  /   \    /
// 3    4   5
// Your Task:
// Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

// Expected Time Complexity: O(N*N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1<=Number of Nodes<=1000

class Solution
{
public:
    Node *treebuild(int pre[], int prestart, int preend, int in[], int instart, int inend, map<int, int> &mp)
    {
        if (prestart > preend || instart > inend)
            return NULL;
        Node *root = new Node(pre[prestart]); // making the first element of prorder as the root of the tree
        int inidx = mp[root->data];           // finds the index of the root data in the inorder array
        int numsleft = inidx - instart;       // returns the number of indexes to the left of the root present in
        // the inorder array
        root->left = treebuild(pre, prestart + 1, prestart + numsleft, in, instart, inidx - 1, mp);
        root->right = treebuild(pre, prestart + numsleft + 1, preend, in, inidx + 1, inend, mp);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i; // maps value->index
        }
        Node *root = treebuild(pre, 0, n - 1, in, 0, n - 1, mp);
        return root;
    }
};