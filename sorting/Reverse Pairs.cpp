// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
// Example 2:

// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

// Constraints:

// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1
class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high, int &reversePairsCount)
    {
        int j = mid + 1;
        // Iterate over the first half of the array and check how many elements in the second half satisfy the condition nums[i] > 2 * nums[j].
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > 2 * (long long)nums[j])
            {
                j++;
            }
            reversePairsCount += j - (mid + 1); // Count the number of such elements.
        }

        // Merge two sorted sub-arrays.
        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid + 1, k = 0;
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
            {
                temp[k++] = nums[left++];
            }
            else
            {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid)
        {
            temp[k++] = nums[left++];
        }
        while (right <= high)
        {
            temp[k++] = nums[right++];
        }

        // Copy the merged array back to the original array.
        int m = 0;
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high, int &reversePairsCount)
    {
        if (low >= high)
        {
            return;
        }
        int mid = (low + high) >> 1;
        // Recursively sort two halves of the array and merge them.
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid + 1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }

    int reversePairs(vector<int> &nums)
    {
        int reversePairsCount = 0;
        // Call merge sort function to sort the array and count the number of reverse pairs.
        mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
        return reversePairsCount;
    }
};
