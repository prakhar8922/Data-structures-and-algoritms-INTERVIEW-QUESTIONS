// 2597. The Number of Beautiful Subsets
// Medium
// 189
// 68
// Companies
// You are given an array nums of positive integers and a positive integer k.

// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

// Return the number of non-empty beautiful subsets of the array nums.

// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

// Example 1:

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
// Example 2:

// Input: nums = [1], k = 1
// Output: 1
// Explanation: The beautiful subset of the array nums is [1].
// It can be proved that there is only 1 beautiful subset in the array [1].

// Constraints:

// 1 <= nums.length <= 20
// 1 <= nums[i], k <= 1000

class Solution
{
public:
    void subs(int idx, vector<int> &nums, unordered_map<int, int> &mp, int &ans, int k)
    {
        if (idx == nums.size())
        {
            ans++;
            return;
        }
        if (!mp[nums[idx] - k] and !mp[nums[idx] + k])
        { // This code block checks if the difference k exists as a key in the map mp for both nums[idx]-k and nums[idx]+k. If neither exists, it increments the count of nums[idx] in the map and recursively calls subs with the updated map and the next index.
            mp[nums[idx]]++;
            subs(idx + 1, nums, mp, ans, k);
            mp[nums[idx]]--;
        }
        // Recurse without taking this element in the subset
        subs(idx + 1, nums, mp, ans, k);
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        subs(0, nums, mp, ans, k);
        return ans - 1; // Return all of the counted sets - 1 for the empty set
    }
};