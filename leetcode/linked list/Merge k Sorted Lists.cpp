// 23. Merge k Sorted Lists
// Hard
// 16.1K
// 595
// Companies
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

class Solution
{
public:
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        if (left->val < right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
    ListNode *mergelist(vector<ListNode *> &lists, int low, int high)
    {
        if (low > high)
            return NULL;
        if (low == high)
            return lists[low];
        int mid = low + (high - low) / 2;
        ListNode *left = mergelist(lists, low, mid);
        ListNode *right = mergelist(lists, mid + 1, high);
        return merge(left, right);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergelist(lists, 0, lists.size() - 1);
    }
};
O(N log k)
in time complexity and O(log k) in space complexity(depth of the call stack)
