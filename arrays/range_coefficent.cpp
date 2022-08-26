#include<iostream>
using namespace std;
int minElement(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int maxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {

        if (arr[i] > max)
        {

            max = arr[i];
        }
    }
    return max;
}




int main(){
int arr[]={15, 16, 10, 9, 6, 7, 17} ;
int n = sizeof(arr) / sizeof(int);
int range=maxElement(arr,n)-minElement(arr,n);
float coefficent=(float)range/(maxElement(arr,n)+minElement(arr,n));

cout<<"range= "<<range<<endl;
cout<<"coefficent of range = "<<coefficent<<endl;
return 0;
}