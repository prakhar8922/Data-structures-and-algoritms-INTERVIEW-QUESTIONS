// Write a program to print Preorder, Inorder, and Postorder traversal of the tree in a single traversal.

// Example:

// Problem Description:

// We need to write a function allTraversals() which returns us three lists of a preorder, inorder and postorder traversals of the tree at the same time. We are not allowed to write separate codes for each traversal. We want all traversals in a single piece of code, in a single instance.

void allTraversal(node *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<node *, int>> st;
    st.push({root,
             1});
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left,
                         1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right,
                         1});
            }
        }
        // don't push it back again
        else
        {
            post.push_back(it.first->data);
        }
    }
}

// Time Complexity : O(N)

//     Reason : We are visiting every node thrice therefore time complexity will be O(3 * N),
//     which can be assumed as linear time complexity.

//     Space Complexity : O(N)

//     Reason : We are using three lists and a stack to store the nodes.The time complexity will be about O(4 * N),
//     which can be assumed as linear time complexity.