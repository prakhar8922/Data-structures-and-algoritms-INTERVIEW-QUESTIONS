// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int low = 0, high = size(nums) - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            // The pairs which are on the left of the single element, will have the first element in an even position and the second element at an odd position. All the pairs which are on the right side of the single element will have the first position at an odd position and the second element at an even position
            if ((mid % 2 == 0 and nums[mid] == nums[mid + 1]) or (mid % 2 != 0 and nums[mid] == nums[mid - 1]))
            {
                low = mid + 1;
            }
            else
                high = mid;
        }
        return nums[low];
    }
};