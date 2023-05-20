
// 1721. Swapping Nodes in a Linked List
// Medium
// 4.7K
// 156
// Companies
// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 105
// 0 <= Node.val <= 100

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k - 1; i++)
        {
            right_ptr = right_ptr->next;
        }

        ListNode *end_ptr = right_ptr;
        while (right_ptr->next)
        {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }

        swap(end_ptr->val, left_ptr->val);

        return head;
    }
};