// 2580. Count Ways to Group Overlapping Ranges
// Medium
// 129
// 9
// Companies
// You are given a 2D integer array ranges where ranges[i] = [starti, endi] denotes that all integers between starti and endi (both inclusive) are contained in the ith range.

// You are to split ranges into two (possibly empty) groups such that:

// Each range belongs to exactly one group.
// Any two overlapping ranges must belong to the same group.
// Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.

// For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur in both ranges.
// Return the total number of ways to split ranges into two groups. Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: ranges = [[6,10],[5,15]]
// Output: 2
// Explanation:
// The two ranges are overlapping, so they must be in the same group.
// Thus, there are two possible ways:
// - Put both the ranges together in group 1.
// - Put both the ranges together in group 2.
// Example 2:

// Input: ranges = [[1,3],[10,20],[2,5],[4,8]]
// Output: 4
// Explanation:
// Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
// Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group.
// Thus, there are four possible ways to group them:
// - All the ranges in group 1.
// - All the ranges in group 2.
// - Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
// - Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.

// Constraints:

// 1 <= ranges.length <= 105
// ranges[i].length == 2
// 0 <= starti <= endi <= 109'

class Solution
{
public:
    int countWays(vector<vector<int>> &ranges)
    {
        int ans = 1, last = -1, mod = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        for (auto &r : ranges)
        {
            if (last < r[0])
                ans = (ans * 2) % mod;
            // r[0] starts a new group,
            //  can be either the first or the second group,
            //  so res should be doubled.

            // the current range is not covered by any of the previous ranges, so there are two options for each integer in the current range: it can either be included or excluded. Therefore, the total number of ways to select integers from all the ranges is doubled.
            last = max(last, r[1]);
        }
        return ans;
    }
};

// def countWays(self, ranges: List[List[int]]) -> int:
//         last,mod,ans=-1,1e9+7,1

//         for r in sorted(ranges):
//             if r[0]>last:
//                 ans=(ans*2)%mod
//             last=max(last,r[1])

//         return int(ans)