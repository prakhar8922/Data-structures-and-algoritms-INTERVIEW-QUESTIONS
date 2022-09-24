// Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.

// Example 1:

// Input:
// N = 4, M = 3
// valueN[] = {5,10,15,40}
// valueM[] = {2,3,20}
// Output: 2 3 5 10 15 20 40
// Explanation: After merging the two linked
// lists, we have merged list as 2, 3, 5,
// 10, 15, 20, 40.
// Example 2:

// Input:
// N = 2, M = 2
// valueN[] = {1,1}
// valueM[] = {2,4}
// Output:1 1 2 4
// Explanation: After merging the given two
// linked list , we have 1, 1, 2, 4 as
// output.
// Your Task:
// The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N, M <= 104
// 1 <= Node's data <= 105

#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    if (head1->data <= head2->data)
    {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}
