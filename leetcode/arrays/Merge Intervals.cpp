// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &interval)
    {
        vector<vector<int>> ans;
        if (interval.size() == 0)
            return ans;
        sort(interval.begin(), interval.end());
        ans.push_back(interval[0]);
        // j is an index to keep track of the last interval in the ans vector
        int j = 0;

        for (int i = 1; i < interval.size(); i++)
        {
            // if the end time of the last interval in the ans vector is greater than or equal to the start time of the current interval
            if (ans[j][1] >= interval[i][0])
            {
                // update the end time of the last interval in the ans vector to be the maximum of the current end time and the end time of the last interval
                ans[j][1] = max(ans[j][1], interval[i][1]);
            }
            // if the end time of the last interval in the ans vector is less than the start time of the current interval
            else
            {

                ans.push_back(interval[i]);
                // update the index j to be the last interval in the ans vector
                j++;
            }
        }

        return ans;
    }
};