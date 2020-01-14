#include <iostream>
using namespace std;
int search(int arr[],int start,int end){
    if(start>end){
        return arr[0];
    }
    if(start==end){
        return arr[start];
    }
    int mid = start+(end-start)/2;
    if(mid<end&&arr[mid]>arr[mid+1]){
        return arr[mid+1];
    }
    if(mid>start&&arr[mid]<arr[mid-1]){
        return arr[mid];
    }
    if(arr[mid]<arr[end]){
        return search(arr,start,mid-1);
    }
    return search(arr,mid+1,end);
}
int main() {
	//code
	int t;
	cin>>t;
	int n;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<search(arr,0,n-1)<<endl;
	}
	return 0;
}
