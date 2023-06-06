// 82. Remove Duplicates from Sorted List II
// Medium
// 7.6K
// 207
// Companies
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.
// Accepted
// 603.5K
// Submissions
// 1.3M
// Acceptance Rate
// 46.1%

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        ListNode *curr = head;

        while (curr && curr->next)
        {
            if (curr->val != curr->next->val)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            { // It identifies the duplicates by comparing the current node's value (curr->val) with a stored value (val), and then iteratively deletes those duplicate nodes while updating the pointers to maintain the integrity of the linked list structure.
                int val = curr->val;
                while (curr && curr->val == val)
                {
                    ListNode *temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            }
        }

        return dummy->next;
    }
};