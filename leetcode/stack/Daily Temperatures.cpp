// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {

            // Popping all indices with a lower or equal temperature than the current index
            while (!st.empty() && arr[i] >= arr[st.top()])
                st.pop();

            // If the stack still has elements, then the next warmer temperature exists!
            if (!st.empty())
                ans[i] = st.top() - i;

            // Inserting current index in the stack: monotonicity is maintained!
            st.push(i);
        }

        return ans;
    }
};