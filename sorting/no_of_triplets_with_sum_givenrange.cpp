#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int countTripletsLessThan(int arr[], int n, int val) {
        // sort the input array.
        sort(arr, arr + n);

        // Initialize result
        int ans = 0;

        int j, k;

        // to store sum
        int sum;

        // Fix the first element
        for (int i = 0; i < n - 2; i++) {

            // Initialize other two elements as
            // corner elements of subarray arr[j+1..k]
            j = i + 1;
            k = n - 1;

            // Use Meet in the Middle concept.
            while (j < k) {
                sum = arr[i] + arr[j] + arr[k];

                // If sum of current triplet
                // is greater, then to reduce it
                // decrease k.
                if (sum > val) k--;

                // If sum is less than or equal
                // to given value, then add
                // possible triplets (k-j) to result.
                else {
                    ans += (k - j);
                    j++;
                }
            }
        }

        return ans;
    }

    // Function to return count of triplets having
    // sum in range [a, b].
    int countTriplets(int Arr[], int N, int L, int R) {

        // to store count of triplets.
        int res;

        // Find count of triplets having sum less
        // than or equal to b and subtract count
        // of triplets having sum less than or
        // equal to a-1.
        res = countTripletsLessThan(Arr, N, R) -
              countTripletsLessThan(Arr, N, L - 1);

        return res;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;