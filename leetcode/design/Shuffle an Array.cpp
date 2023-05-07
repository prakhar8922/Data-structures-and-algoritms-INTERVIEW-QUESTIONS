// 384. Shuffle an Array
// Medium
// 1.1K
// 842
// Companies
// Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

// Implement the Solution class:

// Solution(int[] nums) Initializes the object with the integer array nums.
// int[] reset() Resets the array to its original configuration and returns it.
// int[] shuffle() Returns a random shuffling of the array.

// Example 1:

// Input
// ["Solution", "shuffle", "reset", "shuffle"]
// [[[1, 2, 3]], [], [], []]
// Output
// [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

// Explanation
// Solution solution = new Solution([1, 2, 3]);
// solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
//                        // Any permutation of [1,2,3] must be equally likely to be returned.
//                        // Example: return [3, 1, 2]
// solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
// solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

// Constraints:

// 1 <= nums.length <= 50
// -106 <= nums[i] <= 106
// All the elements of nums are unique.
// At most 104 calls in total will be made to reset and shuffle.

class Solution
{
public:
    vector<int> org;
    int n;
    Solution(vector<int> &nums)
    {
        org = nums;
        n = nums.size();
    }

    vector<int> reset()
    {
        return org;
    }

    vector<int> shuffle()
    {
        vector<int> temp = org;
        int size = n;
        for (int i = n - 1; i >= 0; i--)
        {
            // We maintain two parts of the array, the already-shuffled part, and the unshuffled part. The unshuffled part is at the beginning of the array, and the shuffled part is built from the last element onwards. At every iteration, we draw an element from the unshuffled part and swap it with the current element, effectively removing the drawn element and adding the replaced element to the bag. Then we reduce the size of the bag to account for the reduction in size of the unshuffled part.

            int j = rand() % size;
            swap(temp[i], temp[j]);
            size--;
        }
        return temp;
    }
};
