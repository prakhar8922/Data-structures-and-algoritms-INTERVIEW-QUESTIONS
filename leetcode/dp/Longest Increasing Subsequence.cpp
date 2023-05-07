// 300. Longest Increasing Subsequence
// Medium
// 17K
// 321
// Companies
// Given an integer array nums, return the length of the longest strictly increasing
// subsequence
// .

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

// Accepted
// 1.2M
// Submissions
// 2.3M
// Acceptance Rate
// 52.2%

class Solution
{
public:
    // The idea is to maintain a temporary vector (temp) that represents a pile of cards. Each element in the input vector nums is considered as a card that needs to be added to the pile.
    // Initially, the pile is empty and the first card (i.e., the first element of nums) is added to the pile. For each subsequent card, we check if it is greater than the last card in the pile. If it is, we simply add it to the pile. If it is not, we find the smallest card in the pile that is greater than or equal to the current card using binary search. We then replace that card with the current card. By doing so, we ensure that the pile always represents a valid LIS.
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};

class Solution
{
public:
    int func(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        // base case: if we have reached the end of the array, return 0
        if (idx == nums.size())
        {
            return 0;
        }

        if (dp[idx][prev + 1] != -1)
        {
            return dp[idx][prev + 1];
        }

        int pick = 0, nonpick = 0;

        // if the previous element is not set, or the current element is greater than the previous element
        if (prev == -1 || nums[idx] > nums[prev])
        {
            // choose the current element and recursively call the function for the next index with the current index as the new previous
            pick = 1 + func(idx + 1, idx, nums, dp);
        }

        // skip the current element and recursively call the function for the next index with the previous index remaining unchanged
        nonpick = func(idx + 1, prev, nums, dp);

        dp[idx][prev + 1] = max(nonpick, pick);

        return dp[idx][prev + 1];
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return func(0, -1, nums, dp);
    }
};