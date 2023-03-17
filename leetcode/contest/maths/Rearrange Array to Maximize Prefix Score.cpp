// 2587. Rearrange Array to Maximize Prefix Score
// Medium
// 79
// 7
// Companies
// You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).

// Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it. The score of nums is the number of positive integers in the array prefix.

// Return the maximum score you can achieve.

// Example 1:

// Input: nums = [2,-1,0,1,-3,3,-3]
// Output: 6
// Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
// prefix = [2,5,6,5,2,2,-1], so the score is 6.
// It can be shown that 6 is the maximum score we can obtain.
// Example 2:

// Input: nums = [-2,-3,0]
// Output: 0
// Explanation: Any rearrangement of the array will result in a score of 0.

// Constraints:

// 1 <= nums.length <= 105
// -106 <= nums[i] <= 106

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        long long sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > 0)
                count++;
            else
                break;
        }
        return count;
    }
};

// class Solution:
//     def maxScore(self, nums: List[int]) -> int:
//         sum,count=0,0
//         nums.sort(reverse=True)
//         for i in range(len(nums)):
//             sum+=nums[i]
//             if sum>0:
//                 count+=1
//             else:
//                 break
//         return count