// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next or k == 0)
            return head;
        int len = 1;
        ListNode *temp = head;
        while (temp->next)
        {
            len++;
            temp = temp->next;
        }
        // The k value is updated to k % len to ensure that k is in the range of the length of the linked list. Then, k is updated to len - k so that it can be used to find the correct node to make the new head.
        k = k % len;
        k = len - k;
        // The next pointer of the last node of the linked list is updated to point to the head node, effectively creating a circular linked list.
        temp->next = head;
        while (k--)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};