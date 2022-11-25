// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation:
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int> left(n, -1), right(n, n);
        // for every i find the Next smaller element to left and right

        // Left
        stack<int> st; /// stack stores the index of next smaller element to its left and right
        for (int i = 0; i < n; i++)
        {
            while (st.size() && arr[i] < arr[st.top()])
                st.pop();
            if (st.size())
                left[i] = i - st.top(); // length of subaaray having next smaller element to its
            // left and itself
            else
                left[i] = i + 1; // if no element in the stack then push its index to the stack
            st.push(i);
        }

        while (st.size())
            st.pop();

        // Right
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[i] <= arr[st.top()])
                st.pop();
            if (st.size())
                right[i] = st.top() - i; // length of subaaray having next smaller element to its
            // right and itself
            else
                right[i] = n - i; // if no element in the stack then push its index to the stack
            st.push(i);
        }

        // for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;

        // for each i, contribution is (Left * Right) * Element

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            long long prod = (left[i] * right[i]) % MOD;
            prod = (prod * arr[i]) % MOD;
            res = (res + prod) % MOD;
        }

        return res % MOD;
    }
};
