// You are given an array nums of n positive integers.

// You can perform two types of operations on any element of the array any number of times:

// If the element is even, divide it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
// If the element is odd, multiply it by 2.
// For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
// The deviation of the array is the maximum difference between any two elements in the array.

// Return the minimum deviation the array can have after performing some number of operations.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 1
// Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
// Example 2:

// Input: nums = [4,1,5,20,3]
// Output: 3
// Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
// Example 3:

// Input: nums = [2,10,8]
// Output: 3

// Constraints:

// n == nums.length
// 2 <= n <= 5 * 104
// 1 <= nums[i] <= 109

class Solution
{
public:
    // The intuition behind this logic is to reduce the maximum difference between any two elements in the array by either decreasing the maximum value or increasing the minimum value.
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int mn = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                nums[i] *= 2;
            }
            pq.push(nums[i]);
            mn = min(mn, nums[i]);
        }

        while (!pq.empty())
        {
            auto num = pq.top();
            pq.pop();
            ans = min(ans, num - mn);
            if (num % 2 != 0)
                break;
            num /= 2;
            mn = min(mn, num);
            pq.push(num);
        }
        return ans;
    }
    // the function first converts all odd numbers to even numbers by multiplying them by 2, and then pushes them into a priority queue. It then repeatedly removes the maximum even number from the priority queue, divides it by 2 to make it even, updates the minimum even number seen so far, and pushes the updated even number back into the priority queue. This process continues until the maximum even number in the priority queue becomes odd. Finally, the function returns the minimum difference between the maximum and minimum even numbers seen so far.
};