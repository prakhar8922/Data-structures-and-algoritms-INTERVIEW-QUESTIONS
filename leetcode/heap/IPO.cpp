// 502. IPO
// Hard
// 1.8K
// 133
// Companies
// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

// Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

// The answer is guaranteed to fit in a 32-bit signed integer.

// Example 1:

// Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
// Output: 4
// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
// After finishing it you will obtain profit 1 and your capital becomes 1.
// With capital 1, you can either start the project indexed 1 or the project indexed 2.
// Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
// Example 2:

// Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
// Output: 6

// Constraints:

// 1 <= k <= 105
// 0 <= w <= 109
// n == profits.length
// n == capital.length
// 1 <= n <= 105
// 0 <= profits[i] <= 104
// 0 <= capital[i] <= 109

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++)
        {
            projects[i] = {capital[i], profits[i]};
        }
        // We sort the projects by their minimum capital required in ascending order because we want to consider the projects that we can afford with our current capital. By iterating over the sorted projects, we can ensure that we only consider the projects that have a minimum capital requirement less than or equal to our current capital.
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--)
        {
            // The condition projects[i].first <= w checks if the minimum capital requirement of the next project is less than or equal to our current capital w. If this condition is true, we can add the project to the priority queue because we have enough capital to start the project.
            // We use this condition to ensure that we only add the available projects that we can afford to the priority queue. By checking the minimum capital requirement of the next project before adding it to the priority queue, we can avoid adding projects that we cannot afford, and we can focus on selecting the most profitable project that we can afford with our current capital.
            // The loop while (i < n && projects[i].first <= w) runs until we add all the available projects that we can afford to the priority queue
            while (i < n && projects[i].first <= w)
            {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};