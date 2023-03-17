// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummynode = new ListNode(0);
        ListNode *curr = dummynode;
        while (left and right)
        {
            if (left->val < right->val)
            { // it compares the values of the nodes in left and right and appends the node with the smaller value to the merged list. The pointer curr is then updated to point to the node that was just appended to the merged list.
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left)
            curr->next = left; // if left is not empty, then curr->next is set to left, and if right is not empty, then curr->next is set to right. This is because, at this point, either left or right (or both) will be empty, so we just append the non-empty list to the merged list.
        else
            curr->next = right;
        return dummynode->next;
    }
    ListNode *getmid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // return left middle node in the case of even length LL
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head or !head->next)
            return head;
        ListNode *mid = getmid(head);
        ListNode *left = head;       // The left pointer will be used to represent the left half of the linked list.
        ListNode *right = mid->next; // The right pointer will be used to represent the right half of the linked list.
        mid->next = NULL;            // This line of code sets the next pointer of the middle node mid to NULL, effectively splitting the linked list into two halves, represented by the left and right pointers.
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};