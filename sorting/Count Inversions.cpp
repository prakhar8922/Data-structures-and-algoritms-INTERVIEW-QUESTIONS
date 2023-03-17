// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already
// sorted so there is no inversion count.
// Example 3:

// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array
// are same, so there is no inversion count.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 5*105
// 1 ≤ arr[i] ≤ 1018

#define ll long long
class Solution
{

public:
    long long int merge(long long arr[], long long low, long long mid, long long high)
    {

        long long ans = 0, n1 = mid - low + 1, n2 = high - mid;
        long long left[n1], right[n2];

        for (long long i = 0; i < n1; i++)
            left[i] = arr[i + low];

        for (long long i = 0; i < n2; i++)
            right[i] = arr[mid + 1 + i];

        long long i = 0, j = 0, k = low;

        while (i < n1 && j < n2)
        {

            if (left[i] > right[j])
            {
                ans += n1 - i; // all the elements in left array that are on the right of i element will also be greater than the j th element
                arr[k++] = right[j++];
            }
            else
                arr[k++] = left[i++];
        }

        while (i < n1)
            arr[k++] = left[i++];

        while (j < n2)
            arr[k++] = right[j++];

        return ans;
    }

    long long int mergeSort(long long arr[], long long l, long long r)
    {

        long long ans = 0;
        if (r > l)
        {
            long long mid = l + (r - l) / 2;
            ans += mergeSort(arr, l, mid);
            ans += mergeSort(arr, mid + 1, r);
            ans += merge(arr, l, mid, r);
        }

        return ans;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N - 1);
    }
};