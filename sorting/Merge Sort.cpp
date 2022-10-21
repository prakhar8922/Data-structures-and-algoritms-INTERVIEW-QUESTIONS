// Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
// Example 1:

// Input:
// N = 5
// arr[] = {4 1 3 9 7}
// Output:
// 1 3 4 7 9
// Example 2:

// Input:
// N = 10
// arr[] = {10 9 8 7 6 5 4 3 2 1}
// Output:
// 1 2 3 4 5 6 7 8 9 10

// Your Task:
// You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 103

class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int n1 = m - l + 1, n2 = r - m;
        int left[n1], right[n2];

        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            right[i] = arr[m + 1 + i];

        int i = 0, j = 0, k = l;

        while (i < n1 and j < n2)
        {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while (i < n1)
            arr[k++] = left[i++];
        while (j < n2)
            arr[k++] = right[j++];
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};