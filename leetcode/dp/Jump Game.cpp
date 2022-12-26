// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105
// Accepted
// 1,247,061
// Submissions
// 3,229,195

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reachable = 0; // max reachable index that can be reached till now while iterating the indexes
        // it is initially 0 as max reachable index at the starting is 0
        for (int i = 0; i < n; i++)
        {
            if (i > reachable) // if the current index is greater than the reachable than there is a point in the array further which we cant move and hence the index became greater than reachable
                return false;
            reachable = max(reachable, i + nums[i]); // we will calculate the max reach for every index and compare it with earlier reachable ans
        }
        return true;
    }
};

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int minjump = 0; // min jumps required to reach the last index
        // minjump for last index would be 0 as it is already at last index
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            minjump++;
            if (nums[i] >= minjump) // if the element present at index i has value greater than minjump than it can reach last index and hence minjump would be 0
                minjump = 0;
        }
        return minjump == 0;
    }
};