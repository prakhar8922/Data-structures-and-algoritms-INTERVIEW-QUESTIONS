// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

class Solution
{
private:
    int houserobber(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int curr = max(prev + nums[i], prev2);
            prev = prev2;
            prev2 = curr;
        }
        return prev2;
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        //         As houses are circular and we cannot rob house 1 and n together, so we have 2 choices:

        // 1> Rob houses from 1 to n-1
        // 2> Rob houses from 2 to n
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(houserobber(v1), houserobber(v2));
    }
};