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
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        long long maxProd = arr[0];
        long long maxVal = arr[0];
        long long minVal = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
                swap(maxVal, minVal);
            // we multiply 1ll so that the term arr[i]*1ll becomes of long long type and there is not integer overflow
            maxVal = max(arr[i] * 1ll, maxVal * arr[i]);
            minVal = min(arr[i] * 1ll, minVal * arr[i]);
            maxProd = max(maxProd, maxVal);
        }
        return maxProd;
    }
};
