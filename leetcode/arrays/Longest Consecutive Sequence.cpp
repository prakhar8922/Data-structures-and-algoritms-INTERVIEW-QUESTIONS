// 128. Longest Consecutive Sequence
// Medium
// 15.1K
// 627
// Companies
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet.
        unordered_set<int> set;
        for (int num : nums)
        {
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for (int num : nums)
        {
            if (set.find(num - 1) == set.end())
            {
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while (set.find(currentNumber + 1) != set.end())
                {
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};