// 875. Koko Eating Bananas
// Medium
// 7.2K
// 331
// Companies
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

class Solution
{
public:
    long long getHoursToEatAll(vector<int> &piles, int bananasPerHour)
    {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);
            totalHours += hoursToEatPile;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int> &piles, int targetHours)
    {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));
        int ans = -1;
        //================================================================
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long hoursToEatAll = getHoursToEatAll(piles, mid);

            if (hoursToEatAll <= targetHours)
            {
                ans = mid; // record the answer (this is the best we could record till curr step)
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        //=================================================================
        return ans;
    }
};

// class Solution:
//     def minEatingSpeed(self, piles: List[int], h: int) -> int:
//         lo, hi, k = 1, max(piles), -1

//         while lo <= hi:
//             mid = lo + ((hi - lo) >> 1)

//             if self.numOfHours(mid, piles) <= h:
//                 k = mid
//                 hi = mid - 1
//             else:
//                 lo = mid + 1

//         return k

//     def numOfHours(self, k: int, piles: List[int]) -> int:
//         totalHours = 0
//         for pile in piles:
//             totalHours += math.ceil(pile / k)

//         return totalHours
