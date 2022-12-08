// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string ans = "";
        int fact = 1;
        vector<int> set;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            set.push_back(i);
        }
        set.push_back(n);
        k = k - 1; // to covert k into 0 indexing
        while (true)
        {
            ans += to_string(set[k / fact]);   // selects the k/fact number from set
            set.erase(set.begin() + k / fact); // deletes that number
            if (set.size() == 0)
                break;
            k = k % fact;
            fact = fact / set.size();
        }
        return ans;
    }
};
//  we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more positions and three more numbers. Now the problem is shorter.