// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

// Example 1:

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
// Explanation:
// Arr3  + Arr4 =700,
// which is maximum.

// Example 2:

// Input:
// N = 4, K = 4
// Arr = [100, 200, 300, 400]
// Output:
// 1000
// Explanation:
// Arr1 + Arr2 + Arr3
// + Arr4 =1000,
// which is maximum.

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function maximumSumSubarray() which takes the integer k, vector Arr with size N, containing the elements of the array and returns the maximum sum of a subarray of size K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=N<=106
// 1<=K<=N
class Solution
{
public:
    long maximumSumSubarray(int k, vector<int> &arr, int n)
    {
        // code here
        int i = 0, j = 0;
        long sum = 0, max_sum = INT_MIN;
        while (j < n)
        {
            sum += arr[j];
            if ((j - i + 1) < k)
                j++;
            else if ((j - i + 1) == k)
            {
                max_sum = max(max_sum, sum);
                sum -= arr[i];
                i++, j++;
            }
        }
        return max_sum;
    }
};