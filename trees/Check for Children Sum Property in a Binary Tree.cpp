// Problem Statement: Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.

// The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

// Note:

// The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
// A value for a NULL node can be assumed as 0.
// You are not allowed to change the structure of the given binary tree.

void changeTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    if (sum < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else if (sum >= root->data)
    {
        root->data = sum;
    }
    // traverse
    changeTree(root->left);
    changeTree(root->right);
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left or root->right)
        root->data = total;
}