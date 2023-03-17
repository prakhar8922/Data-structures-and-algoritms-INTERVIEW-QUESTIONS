// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

// Example 1:

// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// Explanation: Subarray with maximum product
// is [6, -3, -10] which gives product as 180.
// Example 2:

// Input:
// N = 6
// Arr[] = {2, 3, 4, 5, -1, 0}
// Output: 120
// Explanation: Subarray with maximum product
// is [2, 3, 4, 5] which gives product as 120.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
// Note: Use 64-bit integer data type to avoid overflow.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 500
// -102 ≤ Arri ≤ 102

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int maxProd = 1;
        int minProd = 1; // The reason for tracking both the maximum and minimum products is that a negative number can make a small product become large, and a large product become small.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxProd, minProd);
            maxProd = max(maxProd * nums[i], nums[i]);
            minProd = min(minProd * nums[i], nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};