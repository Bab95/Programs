#include <bits/stdc++.h>

using namespace std;
class Solution{
public:	
    int N;
    int binarySearch(int arr[],int low,int high){
        if(low>high){
            return -1;
        }
        int mid = (low + high)/2;
        if(mid>0&&arr[mid]<arr[mid-1]){
            return mid;
        }else if(mid<N-1&&arr[mid]>arr[mid+1]){
            return mid+1;
        }else{
            if(arr[low]>=arr[mid]){
                return binarySearch(arr,low,mid-1);
            }else{
                //When 0 rotation this will run.....
                return binarySearch(arr,mid+1,high);
            }
        }
        return -1;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    N = n;
	    int k = binarySearch(arr,0,n-1);
	    if(k==-1){
	        return 0;
	    }
	    return k;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends