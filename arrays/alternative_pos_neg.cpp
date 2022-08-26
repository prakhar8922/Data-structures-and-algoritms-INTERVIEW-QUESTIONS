#include<iostream>
using namespace std;
void alternateNeg_Pos(int arr[],int n){

 for (int i = 0; i < n; i++)
 {
    for (int j = 0; j < n; j++)
    {
         if(i%2==0&& arr[j]<0){
          
            arr[i]=arr[j];
            
          
 
         }
         else if(i%2==0&& arr[j]>0){
          
            arr[i+1]=arr[j];

          
 
         }
    }
    
 }
 

}
int main(){
int arr[]={1, 2, 3, -4, -1, 4};
 int n = sizeof(arr) / sizeof(arr[0]);
return 0;
}
// will do later after doing med  and low difficulty level questions