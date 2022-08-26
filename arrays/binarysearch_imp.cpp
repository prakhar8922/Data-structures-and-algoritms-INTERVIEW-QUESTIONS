#include <bits/stdc++.h>
using namespace std;
// binary_search(start_ptr, end_ptr, num) : This function returns boolean true if the element is present in the container,
//  else returns false.
//   lower_bound(start_ptr, end_ptr, num) : Returns pointer to “position of num” if container contains 1 occurrence of num.
//    Returns pointer to “first position of num” if container contains multiple occurrence of num. Returns pointer 
//    to “position of next higher number than num” if container does not contain occurrence of num. Subtracting the
//     pointer to 1st position i.e “vect.begin()” returns the actual index.
//  lower_bound(Arr.begin(), Arr.end(), k) - Arr.begin();

int binarySearch(int array[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
