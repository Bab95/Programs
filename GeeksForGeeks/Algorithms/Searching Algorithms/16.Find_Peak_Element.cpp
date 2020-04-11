// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int findPeak(int arr[],int start,int end,int n){
    int mid = (start+end)/2;
    if((mid==0||arr[mid]>=arr[mid-1])&&(mid==n-1||arr[mid]>arr[mid+1])){
        return mid;
    }else if(mid>0&&arr[mid-1]>arr[mid]){
        return findPeak(arr,start,mid-1,n);
    }else{
        return findPeak(arr,mid+1,end,n);
    }
    return -1;
}
int peakElement(int arr[], int n)
{
   // Your code here
   int ans = findPeak(arr,0,n-1,n);
   //cout<<ans<<endl;
   return ans;
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}  // } Driver Code Ends