// Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

// Example 1:

// Input:
// N = 8
// in[] = 4 8 2 5 1 6 3 7
// post[] =8 4 5 2 6 7 3 1
// Output: 1 2 4 8 5 3 6 7
// Explanation: For the given postorder and
// inorder traversal of tree the  resultant
// binary tree will be
//            1
//        /      \
//      2         3
//    /  \      /  \
//   4    5    6    7
//    \
//      8

// Example 2:

// Input:
// N = 5
// in[] = 9 5 2 3 4
// post[] = 5 9 3 4 2
// Output: 2 9 5 4 3
// Explanation:
// the  resultant binary tree will be
//            2
//         /     \
//        9       4
//         \     /
//          5   3

// Your Task:
// You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.
// The generated output contains the preorder traversal of the constructed tree.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 103
// 1 <= in[i], post[i] <= 103

Node *treebuild(int post[], int poststart, int postend, int in[], int instart, int inend, map<int, int> &mp)
{
    if (poststart > postend || instart > inend)
        return NULL;
    Node *root = new Node(post[postend]);
    int inidx = mp[post[postend]];
    int numsleft = inidx - instart;
    root->left = treebuild(post, poststart, poststart + numsleft - 1, in, instart, inidx - 1, mp);
    root->right = treebuild(post, poststart + numsleft, postend - 1, in, inidx + 1, inend, mp);
    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    Node *root = treebuild(post, 0, n - 1, in, 0, n - 1, mp);
    return root;
}