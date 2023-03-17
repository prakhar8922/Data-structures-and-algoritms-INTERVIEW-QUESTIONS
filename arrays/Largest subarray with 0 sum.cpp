// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.
// Your Task:
// You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// -1000 <= A[i] <= 1000, for each valid i

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        // Your code here

        // The idea is to iterate through the array and for every element arr[i], calculate sum of elements form 0 to i (simply do sum += arr[i]).
        //  If the current sum has been seen before, then there is a zero sum array.
        unordered_map<int, int> mp;
        int maxlength = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
                maxlength = i + 1;
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    maxlength = max(maxlength, i - mp[sum]);
                }
                else
                    mp[sum] = i;
            }
        }
        return maxlength;
    }
};