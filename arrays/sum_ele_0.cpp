#include <iostream>
using namespace std;
int sumELE(int arr[], int n,int sum)
{
    int curr_sum, i, j;
 
    // Pick a starting point
    for (i = 0; i < n; i++) {
        curr_sum = arr[i];
 
        // try all subarrays starting with 'i'
        for (j = i + 1; j <= n; j++) {
            if (curr_sum ==sum) {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }
            if (curr_sum >sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
 
    cout << "No subarray found";
    return 0;
}
int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum=0;
  cout<<sumELE(arr,n,sum);
    return 0;
}
// do after learning hashing