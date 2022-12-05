// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

// Example 1:

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job.
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
// Example 2:

// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job.
// Profit obtained 150 = 20 + 70 + 60.
// Example 3:

// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6

// Constraints:

// 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
// 1 <= startTime[i] < endTime[i] <= 109
// 1 <= profit[i] <= 104

class Solution
{
    vector<int> dp;

private:
    int mxPro(vector<vector<int>> &events, int idx, int end)
    {
        if (idx == events.size())
            return 0;
        if (events[idx][0] < end) // if starting time is less than the ending time of the last job
            return mxPro(events, idx + 1, end);
        if (dp[idx] != -1)
            return dp[idx];
        int ans = max(events[idx][2] + mxPro(events, idx + 1, events[idx][1]), mxPro(events, idx + 1, end)); // if you take the job and if you dont take it
        return dp[idx] = ans;
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> events(startTime.size(), vector<int>(3, 0));
        for (int i = 0; i < startTime.size(); i++)
        {
            events[i][0] = startTime[i];
            events[i][1] = endTime[i];
            events[i][2] = profit[i];
        }
        sort(events.begin(), events.end());
        int n = events.size();
        dp.resize(n, -1);
        return mxPro(events, 0, 0);
    }
};