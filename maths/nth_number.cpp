#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    	long long findNth(long long n)
    {  // int count=n;
    long long ans=0;
    long long temp=1;
    while(n>0){
        
        
        ans+=temp*(n%9);
        temp*=10;
        n/=9;
    }
    return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}
