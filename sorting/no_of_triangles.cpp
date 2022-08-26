#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
         //Sorting the input array.
        sort(arr, arr+n);

        int count = 0;
        
        //Traversing the array.
        for (int i = 0; i < n-2; ++i)
        {
            //Storing the third index starting from ith index in k.
            int k = i+2;
            
            //Traversing all the elements after ith index.
            for (int j = i+1; j < n; ++j)
            {
                //Traversing all the elements after jth index to check if there
                //exists any element which can satisfy the condition of triangle
                //with the elements at ith, jth and kth index.
                while (k < n && arr[i] + arr[j] > arr[k])
                   ++k;
                
                //Incrementing the count of triangles.
                count += k - j - 1;
            }
        }
        //returning the count of triangles.
        return count;
    }
   
   
// int factorial(int n){
    
//     if(n==0||n==1)
//     return 1;
//     else 
//     return (n*factorial(n-1));
    
// }
    
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends