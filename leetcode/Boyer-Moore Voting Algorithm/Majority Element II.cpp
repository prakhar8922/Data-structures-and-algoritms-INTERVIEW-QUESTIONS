// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

// Follow up: Could you solve the problem in linear time and in O(1) space?

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1, n = nums.size();
        for (auto &it : nums)
        {
            if (it == num1)
                cnt1++;
            else if (it == num2)
                cnt2++;
            else if (cnt1 == 0)
            {
                num1 = it;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                num2 = it;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        if (num1 == num2)
        { // edge case for when both the candidate numbers are same
            ans.push_back(num1);
            return ans;
        }
        cnt1 = 0, cnt2 = 0;
        for (auto &it : nums)
        {
            if (it == num1)
                cnt1++;
            if (it == num2)
                cnt2++;
        }
        if (cnt1 > n / 3)
            ans.push_back(num1);
        if (cnt2 > n / 3)
            ans.push_back(num2);
        return ans;
    }
};