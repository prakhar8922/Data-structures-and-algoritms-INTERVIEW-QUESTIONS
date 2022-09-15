// You are given an array Arr of size N containing non-negative integers. Your task is to choose the minimum number of elements such that their sum should be greater than the sum of the rest of the elements of the array.

// Example 1:

// Input:
// N = 4
// Arr[] = {2, 17, 7, 3}
// Output:
// 1
// Explanation:
// If we only select element 17, the sum of the
// rest of the elements will be (2+3+7)=12.
// So the answer will be 1.
// Example 2:

// Input:
// N = 4
// Arr = {20, 12, 18, 4}
// Output:
// 2
// Explanation:
// If we select 12 and 18 from the array,
// the sum will be (12+18) = 30 and the sum of
// the rest of the elements will be (20+4) = 24.
// So, the answer will be 2. We can also
// select 20 and 18 as well.

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function minSubset() which takes the array Arr[] and its size N as inputs and returns the minimum number of elements to be selected.

// Expected Time Complexity: O(N log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Arr[i] <= 109
// Array may contain duplicate elements.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSubset(vector<int> &Arr, int N)
    {
        sort(Arr.begin(), Arr.end());
        long long sum = 0;

        for (int i = 0; i < N; i++)
            sum += Arr[i];
        long long s = 0;
        for (int i = N - 1; i >= 1; i--)
        {
            s += Arr[i];
            sum -= Arr[i];

            if (s > sum)
                return N - i;
        }
        return 1;
    }
};