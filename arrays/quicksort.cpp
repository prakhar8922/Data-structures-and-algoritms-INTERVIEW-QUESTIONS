#include <iostream>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quicksort(int arr[], int low, int high)
{
    int partitionindex; // Index of pivot after partition
    if (low < high)
    {

        partitionindex = partition(arr, low, high);

        quicksort(arr, low, partitionindex - 1);// sort left subarray 
        quicksort(arr, partitionindex + 1, high);// sort right subarray 
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);
    quicksort(arr,0,n-1);
     printArray(arr,n);
    return 0;
}