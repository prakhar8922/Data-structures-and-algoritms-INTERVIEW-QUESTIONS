// 1402. Reducing Dishes
// Hard
// 2.2K
// 231
// Companies
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

// Example 1:

// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
// Example 2:

// Input: satisfaction = [4,3,2]
// Output: 20
// Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
// Example 3:

// Input: satisfaction = [-1,-4,-5]
// Output: 0
// Explanation: People do not like the dishes. No dish is prepared.

// Constraints:

// n == satisfaction.length
// 1 <= n <= 500
// -1000 <= satisfaction[i] <= 1000

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());

        int maxSatisfaction = 0;
        int suffixSum = 0;
        for (int i = satisfaction.size() - 1; i >= 0 && suffixSum + satisfaction[i] > 0; i--)
        {
            // Total satisfaction with all dishes so far.
            suffixSum += satisfaction[i];
            // Adding one instance of previous dishes as we add one more dish on the left.
            maxSatisfaction += suffixSum;
        }

        return maxSatisfaction;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> memo;
//     int dp(int i, int t, vector<int> &arr)
//     {
//         if (i >= arr.size())
//             return 0;
//         if (memo[i][t] != -1)
//             return memo[i][t];
//         int not_taken = dp(i + 1, t, arr);
//         int taken = arr[i] * t + dp(i + 1, t + 1, arr);
//         return memo[i][t] = max(taken, not_taken);
//     }

//     int maxSatisfaction(vector<int> &arr)
//     {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         memo.resize(n, vector<int>(n + 1, -1));
//         return dp(0, 1, arr);
//     }
// };