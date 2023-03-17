// 2187. Minimum Time to Complete Trips
// Medium
// 1.4K
// 85
// Companies
// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

// Example 1:

// Input: time = [1,2,3], totalTrips = 5
// Output: 3
// Explanation:
// - At time t = 1, the number of trips completed by each bus are [1,0,0].
//   The total number of trips completed is 1 + 0 + 0 = 1.
// - At time t = 2, the number of trips completed by each bus are [2,1,0].
//   The total number of trips completed is 2 + 1 + 0 = 3.
// - At time t = 3, the number of trips completed by each bus are [3,1,1].
//   The total number of trips completed is 3 + 1 + 1 = 5.
// So the minimum time needed for all buses to complete at least 5 trips is 3.
// Example 2:

// Input: time = [2], totalTrips = 1
// Output: 2
// Explanation:
// There is only one bus, and it will complete its first trip at t = 2.
// So the minimum time needed to complete 1 trip is 2.

// Constraints:

// 1 <= time.length <= 105
// 1 <= time[i], totalTrips <= 107

class Solution
{
public:
    // Can these buses finish 'totalTrips' of trips in 'givenTime'?
    bool isValid(vector<int> &time, long long giventime, int totaltrips)
    {
        long long countrips = 0;
        for (auto &t : time)
        {
            countrips += giventime / t;
        }
        return countrips >= totaltrips;
    }
    long long minimumTime(vector<int> &time, int totaltrips)
    {
        long long ans;
        // You can tighten the lower-bound to min(time) because you need to spend at least that much time to carry out a single trip. You can also tighten the upper-bound to min(time) * totalTrips because that much time is sufficient for the fastest bus to perform all trips by itself.
        long long low = *min_element(time.begin(), time.end());
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totaltrips;
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (isValid(time, mid, totaltrips))
            {
                // Assume the time needed is given_time, for bus i, the number of trips it can finish within given_time is given_time / time[i]. Thus the total number of trips is the sum of given_time / time[i] for all buses.
                high = mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

// class Solution:
//     def minimumTime(self, time: List[int], totaltrips: int) -> int:
//         low,high=min(time),min(time)*totaltrips
//         def isValid(giventime):
//             actualtrips=0
//             for t in time:
//                 actualtrips+=giventime//t
//             return actualtrips>=totaltrips

//         while low<high:
//             mid=low+(high-low)//2
//             if isValid(mid):
//                 high=mid
//             else:
//                 low=mid+1

//         return low