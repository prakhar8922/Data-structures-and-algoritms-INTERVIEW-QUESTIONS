
// 1345. Jump Game IV
// Hard
// 2.7K
// 101
// Companies
// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.

// Example 1:

// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
// Example 2:

// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You do not need to jump.
// Example 3:

// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

// Constraints:

// 1 <= arr.length <= 5 * 104
// -108 <= arr[i] <= 108

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i); //{value->(indices) eg-> 404->(3,9)}
        }
        int steps = 0;
        queue<int> q; // for storing indexes
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int currIdx = q.front();
                q.pop();
                if (currIdx == n - 1)
                    return steps;
                if (currIdx + 1 < n and vis[currIdx + 1] == false)
                {
                    q.push(currIdx + 1);
                    vis[currIdx + 1] = true;
                }
                if (currIdx - 1 >= 0 and vis[currIdx - 1] == false)
                {
                    q.push(currIdx - 1);
                    vis[currIdx - 1] = true;
                }
                for (auto &newIdx : mp[arr[currIdx]])
                { //(Move to same valued idx)
                    if (!vis[newIdx])
                    {
                        q.push(newIdx);
                        vis[newIdx] = true;
                    }
                }
                mp[arr[currIdx]].clear(); // If we do not clear mp[arr[currIdx]] at the end of each iteration of the while loop, it will keep storing the indices for the same value and also the indices to which we can jump from the previous iterations as well, leading to incorrect results or time limit exceeded.
                // So, including the statement jumpNextIndices.clear(); at the end of each iteration of the while loop is important to make sure that the jumpNextIndices vector only contains the valid indices for the current iteration.
            }
            steps++;
        }
        return -1;
    }
};