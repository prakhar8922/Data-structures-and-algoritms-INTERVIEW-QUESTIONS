// 109. Convert Sorted List to Binary Search Tree
// Medium
// 6.5K
// 139
// Companies
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
// height-balanced
//  binary search tree.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

class Solution
{
public:
    TreeNode *constructBST(ListNode *leftHead, ListNode *rightHead)
    {

        if (leftHead == rightHead)

            return nullptr;

        ListNode *slow = leftHead, *fast = leftHead;

        while (fast != rightHead && fast->next != rightHead)
        {

            slow = slow->next;

            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);

        root->left = constructBST(leftHead, slow);

        root->right = constructBST(slow->next, rightHead);

        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {

        if (head == nullptr)

            return nullptr;

        return constructBST(head, nullptr); // nullptr is used as the rightHead parameter in the initial call to constructBST to indicate that the end of the list being processed is the end of the linked list.
    }
};

// class Solution:
//     def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
//         if not head:
//             return None
//         return self.func(head,None)

//     def func(self,lefthead:ListNode,righthead:ListNode)->TreeNode:
//         if lefthead==righthead:
//             return None
//         slow,fast=lefthead,lefthead
//         while fast!=righthead and fast.next!=righthead:
//             slow=slow.next
//             fast=fast.next.next
//         root=TreeNode(slow.val)
//         root.left=self.func(lefthead,slow)
//         root.right=self.func(slow.next,righthead)
//         return root