#include <iostream>
using namespace std;
int binarySearch(int arr[],int start,int end){
    if(start==end){
        return start;
    }
    if(start<end){
        int mid = (start+end)/2;
        if(mid%2!=0){
            //mid is even
            if(arr[mid]==arr[mid-1]){
                return binarySearch(arr,mid+1,end);
            }else{
                return binarySearch(arr,start,mid-1);
            }
        }else{
            //mid is odd.....
            if(mid<end){
                if(arr[mid]==arr[mid+1]){
                    return binarySearch(arr,mid+2,end);
                }else{
                    if(mid==0&&arr[mid]!=arr[mid+1]){
                        return 0;
                    }
                    if(mid>0&&arr[mid-1]!=arr[mid]){
                        return mid;
                    }else
                        return binarySearch(arr,start,mid-1);
                }
            }else{
                return mid;
            }
        }
    }
    return -1;
}
int main() {
	//code
	int t;
	int n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int res = binarySearch(arr,0,n-1);
	    //cout<<res<<endl;
	    cout<<arr[res]<<endl;

	}
	return 0;
}
