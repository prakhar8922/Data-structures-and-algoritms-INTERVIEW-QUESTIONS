// Hard

// 12878

// 419

// Add to List

// Share
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int i = 0, j = 0, n = nums.size();
        deque<int> dq;
        while (j < n)
        {
            while (!dq.empty() and dq.back() < nums[j])
            {
                dq.pop_back(); // calculation
            }
            dq.push_back(nums[j]);
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                ans.push_back(dq.front()); // calculation for ans
                if (nums[i] == dq.front()) // sliding window
                    dq.pop_front();
                i++, j++;
            }
        }
        return ans;
    }
};