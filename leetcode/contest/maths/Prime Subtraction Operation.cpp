// 2601. Prime Subtraction Operation
// Medium
// 187
// 26
// Companies
// You are given a 0-indexed integer array nums of length n.

// You can perform the following operation as many times as you want:

// Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
// Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

// A strictly increasing array is an array whose each element is strictly greater than its preceding element.

// Example 1:

// Input: nums = [4,9,6,10]
// Output: true
// Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
// In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
// After the second operation, nums is sorted in strictly increasing order, so the answer is true.
// Example 2:

// Input: nums = [6,8,11,12]
// Output: true
// Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
// Example 3:

// Input: nums = [5,8,3]
// Output: false
// Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// nums.length == n
// Accepted
// 8.4K
// Submissions
// 23.4K
// Acceptance Rate
// 35.9%

#define ll long long int
class Solution
{
public:
    static const int MAX = 1005; // maximum value of the array

    bool prime[MAX]; // boolean array to mark primes

    void sieve()
    {
        fill(prime, prime + MAX, true); // initialize all as prime
        prime[0] = prime[1] = false;    // 0 and 1 are not primes

        // sieve of Eratosthenes algorithm to find primes
        for (int i = 2; i * i < MAX; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j < MAX; j += i)
                {
                    prime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int> &nums)
    {
        sieve(); // find primes using sieve algorithm

        vector<int> primes; // vector to store primes
        for (int i = 2; i < MAX; i++)
        {
            if (prime[i])
                primes.push_back(i);
        }

        int n = nums.size();           // size of the given array
        vector<int> new_nums(n, -1);   // vector to store the new numbers
        new_nums[n - 1] = nums[n - 1]; // set the last number

        // iterate from second last to first element
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < new_nums[i + 1])
            {
                new_nums[i] = nums[i];
                continue;
            }

            // iterate over primes to find a suitable one for subtraction
            for (auto p : primes)
            {
                if (p >= nums[i])
                {
                    new_nums[i] = nums[i];
                    break;
                }
                if (nums[i] - p < new_nums[i + 1])
                {
                    new_nums[i] = nums[i] - p;
                    break;
                }
            }
        }

        // check if the new array is strictly increasing
        for (int i = 1; i < n; i++)
            if (new_nums[i] <= new_nums[i - 1])
                return false;

        return true;
    }
};