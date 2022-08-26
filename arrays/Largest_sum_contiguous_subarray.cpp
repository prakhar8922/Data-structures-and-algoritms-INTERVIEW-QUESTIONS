#include<iostream>
using namespace std;
int  largestSumSubArr(int arr[],int n){
int max_so_far=0,max_here=0;
for (int i = 0; i < n; i++)
{
     max_here+=arr[i];
     if(max_so_far<max_here){

          max_so_far=max_here;
     }
     if(max_here<0){

         max_here=0;
     }

}
return max_so_far;



}
int main(){
int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The sum of the largest subarray in the given array is:"<<largestSumSubArr(arr,n);
return 0;
}