// There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note :- In an inorder traversal the number just smaller than target is predecessor and the number just greater than target is successor.

// Example:

// Input:
// 2
// 6
// 50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
// 65
// 6
// 50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
// 100

// Output:
// 60 70
// 80 -1

// Explanation: In each test case first node is the root. Here, 50 is the root. Here, 50 30 L denotes that node having data 50 has its left child having data 30. Similarly, 30 20 L denotes that node having data 30 has its left child having data 20. Same goes for 30 40 R but here R means node 40 is right child of node 30. So, we can easily draw a bst and in first case, we have find predecessor and successor of 65.
// Now, 65 need not to be present in the tree. Here, we can see 60 is its predecessor and 70 would be its successor. Please note that even if 65 were there in the tree, its predecessor and successor would have been the same because we don't count node itself as predecessor or successor.

// Output:
// Find the predecessor and successor of the key in BST and sets pre and suc as predecessor and successor, respectively Otherwise, set to NULL.

// Your Task: You don't need to print anything. You only need to set p.pre to the predecessor and s.succ to the successor. p and s have been passed in the function parameter.

// Constraints:
// 1<=T<=100
// 1<=n<=100
// 1<=data of node<=100
// 1<=key<=100

Node *successor(Node *root, int key)
{
    Node *suc = NULL;
    while (root)
    {
        if (key >= root->key)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
    return suc;
}
Node *precessor(Node *root, int key)
{
    Node *pre = NULL;
    while (root)
    {
        if (key <= root->key)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    suc = successor(root, key);
    pre = precessor(root, key);
}