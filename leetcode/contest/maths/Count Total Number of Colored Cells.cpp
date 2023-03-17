// 2579. Count Total Number of Colored Cells
// Medium
// 104
// 4
// Companies
// There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

// At the first minute, color any arbitrary unit cell blue.
// Every minute thereafter, color blue every uncolored cell that touches a blue cell.
// Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.

// Return the number of colored cells at the end of n minutes.

// Example 1:

// Input: n = 1
// Output: 1
// Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
// Example 2:

// Input: n = 2
// Output: 5
// Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.

// Constraints:

// 1 <= n <= 105

class Solution
{
public:
    long long coloredCells(int n)
    {
        // for the first n numbers or the upper half the patterns is:1,3,5,...
        // for the bottom half or n-1 numbers in the lower half the pattern is:5,3,1 from the top and 1,3,5,... from the bottom . using ap first n numbers sum=n^2 and n-1 numbers is (n-1)^2
        return pow(n, 2) + pow(n - 1, 2);
    }
};

// class Solution:
//     def coloredCells(self, n: int) -> int:
//         return n**2+(n-1)**2