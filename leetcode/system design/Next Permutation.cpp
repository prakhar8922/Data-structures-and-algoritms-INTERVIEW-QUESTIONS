// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

class Solution
{
public:
    // the intuition behind this code is that when traversing from the end of the array the numbers are always in increasing order from right to left . the first index where the element is smaller than the element on its right is the breaking point and we take it as left index
    void nextPermutation(vector<int> &nums)
    {
        int left, right;
        int n = nums.size();
        // Find the rightmost element that is smaller than its next element
        for (left = n - 2; left >= 0; left--)
        {
            if (nums[left] < nums[left + 1])
                break;
        }

        // If no such element is found, reverse the entire vector
        if (left < 0)
            reverse(nums.begin(), nums.end());

        // Else, find the first element from the end that is greater than the pivot
        else
        {
            for (right = n - 1; right > left; right--)
            {
                if (nums[right] > nums[left])
                    break;
            }

            // Swap the pivot and the element found in step 2
            swap(nums[left], nums[right]);

            // Reverse the elements to the right of the pivot
            reverse(nums.begin() + left + 1, nums.end());
        }
    }
};