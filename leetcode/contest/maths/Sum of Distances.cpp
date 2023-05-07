// 2615. Sum of Distances
// Medium
// 323
// 56
// Companies
// You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

// Return the array arr.

// Example 1:

// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]
// Explanation:
// When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
// When i = 1, arr[1] = 0 because there is no other index with value 3.
// When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
// When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
// When i = 4, arr[4] = 0 because there is no other index with value 2.

// Example 2:

// Input: nums = [0,5,3]
// Output: [0,0,0]
// Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// Accepted
// 9.2K
// Submissions
// 33.2K
// Acceptance Rate
// 27.6%

class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();                               // get the size of the input vector
        unordered_map<long long, vector<long long>> mp;    // create an empty unordered map to store the indices of identical elements
        vector<long long> suf(n, 0), pre(n, 0), ans(n, 0); // create three vectors to store the suffix sum, prefix sum, and final answer

        // loop through the input vector and store the indices of each identical element in the map
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        // loop through each group of identical elements and calculate the prefix sum of their distances
        for (auto [x, y] : mp)
        {
            for (int i = 1; i < y.size(); i++)
            {
                pre[y[i]] = pre[y[i - 1]] + i * (y[i] - y[i - 1]); // update prefix sum with the distance between i-th and i-1-th element
            }
        }

        // loop through each group of identical elements and calculate the suffix sum of their distances
        for (auto [x, y] : mp)
        {
            for (int i = y.size() - 2; i >= 0; i--)
            {
                suf[y[i]] = suf[y[i + 1]] + (y.size() - i - 1) * (y[i + 1] - y[i]); // update suffix sum with the distance between i-th and i+1-th element
            }
        }

        // loop through each element and add its prefix and suffix sum to get the final answer
        for (int i = 0; i < n; i++)
        {
            ans[i] += pre[i] + suf[i];
        }

        return ans; // return the final answer
    }
};