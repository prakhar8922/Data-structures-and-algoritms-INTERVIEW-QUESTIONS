// 2708. Maximum Strength of a Group
// Medium
// 119
// 18
// Companies
// You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].

// Return the maximum strength of a group the teacher can create.

// Example 1:

// Input: nums = [3,-1,-5,2,5,-9]
// Output: 1350
// Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
// Example 2:

// Input: nums = [-4,-5,-4]
// Output: 20
// Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.

// Constraints:

// 1 <= nums.length <= 13
// -9 <= nums[i] <= 9
// Accepted
// 12.7K
// Submissions
// 58.5K
// Acceptance Rate
// 21.6%

class Solution
{
public:
    long long ans = INT_MIN;
    void solve(vector<int> &nums, int index, long long product, int size)
    {
        if (index == nums.size())
        {
            // we need a non empty group
            if (size != 0)
                ans = max(ans, product);
            return;
        }
        solve(nums, index + 1, product * nums[index], size + 1); // pick
        solve(nums, index + 1, product, size);                   // not pick
    }
    long long maxStrength(vector<int> &nums)
    {
        // size denotes the size of the chosen group of students.
        //  In question it is mentioned that no. of students in group cannot be 0
        //  But in recursion there could occur a case where we choose all cases of "NOT PICK"
        //  to handle that we chose atleast one I used the variable "size"
        solve(nums, 0, 1, 0);
        return ans;
    }
};