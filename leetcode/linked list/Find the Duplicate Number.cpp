// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

// Follow up:

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // The intuition here is that:
        //  Index range is [0, n] inclusive, value range is [1, n] inclusive. Value is non-zero and range is always inside of index's range (note that the detect cycling way wouldn't work if array values range is [0, n-1] because if value 0 appears at index 0 then 0 forms a cycle with itself even though 0 might not be a duplicate value.).
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};