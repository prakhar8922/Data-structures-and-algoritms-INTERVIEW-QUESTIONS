// 378. Kth Smallest Element in a Sorted Matrix
// Medium
// 8.9K
// 311
// Companies
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 300
// -109 <= matrix[i][j] <= 109
// All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
// 1 <= k <= n2

// Follow up:

// Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
// Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int count;
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high)
        {
            count = 0;
            int mid = low + (high - low) / 2;
            for (int i = 0; i < n; i++)
            {
                // The function 'upper_bound' is used to find the position of the first element in each row of the matrix that is greater than 'mid'. The difference between this position and the beginning of the row gives the number of elements that are smaller than or equal to 'mid' in that row. The count variable keeps track of the total number of such elements across all rows.
                // By doing this, the code calculates the number of elements in the matrix that are smaller than or equal to the current candidate 'mid' for kth smallest element.
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};