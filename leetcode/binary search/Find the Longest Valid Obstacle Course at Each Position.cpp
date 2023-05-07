// 1964. Find the Longest Valid Obstacle Course at Each Position
// Hard
// 1K
// 37
// Companies
// You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.

// For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:

// You choose any number of obstacles between 0 and i inclusive.
// You must include the ith obstacle in the course.
// You must put the chosen obstacles in the same order as they appear in obstacles.
// Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
// Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.

// Example 1:

// Input: obstacles = [1,2,3,2]
// Output: [1,2,3,3]
// Explanation: The longest valid obstacle course at each position is:
// - i = 0: [1], [1] has length 1.
// - i = 1: [1,2], [1,2] has length 2.
// - i = 2: [1,2,3], [1,2,3] has length 3.
// - i = 3: [1,2,3,2], [1,2,2] has length 3.
// Example 2:

// Input: obstacles = [2,2,1]
// Output: [1,2,1]
// Explanation: The longest valid obstacle course at each position is:
// - i = 0: [2], [2] has length 1.
// - i = 1: [2,2], [2,2] has length 2.
// - i = 2: [2,2,1], [1] has length 1.
// Example 3:

// Input: obstacles = [3,1,5,6,4,2]
// Output: [1,1,2,3,2,2]
// Explanation: The longest valid obstacle course at each position is:
// - i = 0: [3], [3] has length 1.
// - i = 1: [3,1], [1] has length 1.
// - i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
// - i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
// - i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
// - i = 5: [3,1,5,6,4,2], [1,2] has length 2.

// Constraints:

// n == obstacles.length
// 1 <= n <= 105
// 1 <= obstacles[i] <= 107
// Accepted
// 26.9K
// Submissions
// 45.6K
// Acceptance Rate
// 59.1%

class Solution
{
public:
    // This code solves the problem of finding the length of the longest increasing subsequence (LIS) that can be formed using the given obstacle course.

    // The idea behind the code is to use a dynamic programming approach to solve this problem. At each position in the obstacle course, we maintain a vector v of the LIS ending at that position. We then use binary search to find the position to insert the current obstacle in the vector. The value at the index where the obstacle is inserted is updated if necessary.

    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> v;   // initialize a vector to keep track of the LIS so far
        vector<int> ans; // initialize a vector to store the answer
        for (int i = 0; i < obstacles.size(); i++)
        {
            int x = obstacles[i];                                     // get the current obstacle height
            int idx = upper_bound(v.begin(), v.end(), x) - v.begin(); // get the index of the first element in v greater than x using binary search
            if (idx == v.size())
            { // if x is greater than all elements in v, push it to the back
                v.push_back(x);
            }
            else
            { // else update the value at idx to x
                v[idx] = x;
            }
            ans.push_back(idx + 1); // the answer is the length of v so far, which is idx+1
        }
        return ans; // return the answer vector
    }
};