// 86. Partition List
// Medium
// 5.4K
// 625
// Companies
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example 1:

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]

// Constraints:

// The number of nodes in the list is in the range [0, 200].
// -100 <= Node.val <= 100
// -200 <= x <= 200
// Accepted
// 451.4K
// Submissions
// 864.9K
// Acceptance Rate
// 52.2%

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // Create two new linked lists to hold the nodes with values less than x (less)
        // and nodes with values greater than or equal to x (more).
        ListNode *less = new ListNode(0);
        ListNode *more = new ListNode(0);

        // Create two pointers to the heads of the new linked lists.
        ListNode *less_head = less;
        ListNode *more_head = more;

        // Traverse the original linked list.
        while (head)
        {
            // If the current node's value is less than x, append it to the 'less' list.
            if (head->val < x)
            {
                less_head->next = head;
                less_head = less_head->next;
            }
            // If the current node's value is greater than or equal to x, append it to the 'more' list.
            else
            {
                more_head->next = head;
                more_head = more_head->next;
            }

            // Move to the next node in the original linked list.
            head = head->next;
        }

        // Set the 'next' pointer of the last node in the 'more' list to NULL.
        more_head->next = NULL;

        // Connect the end of the 'less' list to the start of the 'more' list.
        less_head->next = more->next;

        // Return the head of the modified linked list, which is the head of the 'less' list.
        return less->next;
    }
};