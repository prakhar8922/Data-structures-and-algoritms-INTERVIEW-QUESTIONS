// 92. Reverse Linked List II
// Medium
// 9.1K
// 414
// Companies
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

// Follow up: Could you do it in one pass?
// Accepted
// 634.8K
// Submissions
// 1.4M
// Acceptance Rate
// 45.5%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head)
            return NULL; // If the list is empty, return NULL
        ListNode *curr = head;
        ListNode *prev = NULL;

        // Move the 'curr' and 'prev' pointers to the left position
        while (left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }

        ListNode *con = prev;  // Node preceding the sublist to be reversed
        ListNode *tail = curr; // Last node of the sublist to be reversed
        ListNode *next = NULL;

        // Reverse the sublist from 'left' to 'right'
        while (right--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed sublist back to the original list
        if (con)
            con->next = prev; // Connect the preceding node to the first node of the reversed sublist
        else
            head = prev; // Update the head of the linked list to the first node of the reversed sublist

        tail->next = curr; // Connect the last node of the reversed sublist to the node that originally followed the sublist

        return head; // Return the head of the modified linked list
    }
};