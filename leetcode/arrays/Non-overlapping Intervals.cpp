// 435. Non-overlapping Intervals
// Medium
// 5.8K
// 158
// Companies
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104
// Accepted
// 363.5K
// Submissions
// 721.4K
// Acceptance Rate
// 50.4%

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1]; // Comparison function to sort intervals based on the end time
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp); // Sort intervals in non-decreasing order of end times
        int n = intervals.size();
        int ans = 0;                // Variable to store the count of overlapping intervals
        int prev = intervals[0][1]; // Store the end time of the first interval

        // Traverse the intervals starting from the second interval
        for (int i = 1; i < n; i++)
        {
            // If the start time of the current interval is less than the previous end time,
            // it indicates an overlap with the previous interval
            if (intervals[i][0] < prev)
            {
                ans++; // Increment the count of overlapping intervals
            }
            else
            {
                prev = intervals[i][1]; // Update the previous end time to the end time of the current interval
            }
        }

        return ans; // Return the count of overlapping intervals
    }
};