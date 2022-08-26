
// #include <iostream>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;
void ThreeLarEle(int arr[],int n){

  sort(arr,arr+n);

  for (int i = n-1; i>=n-3; i--)
  {
   cout<<arr[i]<<" ";

      //cout<<arr[n-1]<<" "<<arr[n-2]<<" "<<arr[n-3];
  }
  

}
int main()
{
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    ThreeLarEle(arr,n);
    return 0;
}

// SORT  function internally uses IntroSort.In more details it is implemented using hybrid of QuickSort,
//  HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning 
//  and taking more than N *logN time, it switches to HeapSort and when the array size becomes really
//   small, it switches to InsertionSort.