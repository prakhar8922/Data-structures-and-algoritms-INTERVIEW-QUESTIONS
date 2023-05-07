// 2300. Successful Pairs of Spells and Potions
// Medium
// 2K
// 42
// Companies
// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

// Example 1:

// Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
// Output: [4,0,3]
// Explanation:
// - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
// - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
// - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
// Thus, [4,0,3] is returned.
// Example 2:

// Input: spells = [3,1,2], potions = [8,5,8], success = 16
// Output: [2,0,2]
// Explanation:
// - 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
// - 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
// - 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
// Thus, [2,0,2] is returned.

// Constraints:

// n == spells.length
// m == potions.length
// 1 <= n, m <= 105
// 1 <= spells[i], potions[i] <= 105
// 1 <= success <= 1010
// Accepted
// 85.8K
// Submissions
// 207.1K
// Acceptance Rate
// 41.5%

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> pair(n);
        for (int i = 0; i < n; i++)
        {
            int low = 0, high = m - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                long long num = (long long)spells[i] * (long long)potions[mid];
                if (num >= success)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            pair[i] = m - low;
        }
        return pair;
    }
};

// class Solution:
//     def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
//         potions.sort()
//         n,m=len(spells),len(potions)
//         pair=[0]*n

//         for i in range(n):
//             low,high=0,m-1
//             while low<=high:
//                 mid=low+(high-low)//2
//                 if spells[i]*potions[mid]>=success:
//                     high=mid-1
//                 else:
//                     low=mid+1;
//             pair[i]=m-low
//         return pair