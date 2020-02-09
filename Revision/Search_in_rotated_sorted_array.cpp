#include <iostream>
using namespace std;
int findPivot(int arr[],int low,int high){
    if(low>high){
        return -1;
    }
    if(low==high){
        return low;
    }
    int mid = (low+high)/2;
    if(mid<high&&arr[mid]>arr[mid+1]){
        return mid;
    }
    if(mid>low&&arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[low]>=arr[mid]){
        return findPivot(arr,low,mid-1);
    }
    return findPivot(arr,mid+1,high);

}
int binarySearch(int arr[],int low,int high,int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}
int main() {
	//code
	int t,n,key;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>key;
	    int pivot = findPivot(arr,0,n-1);
	    //cout<<"pivot is: "<<pivot<<" key is"<<key<<endl;
	    if(pivot==-1||pivot==n-1){
	        cout<<binarySearch(arr,0,n-1,key)<<endl;
	    }else if(arr[pivot]==key){
	        cout<<pivot<<endl;
	    }
	    else if(key>=arr[0]){
	        cout<<binarySearch(arr,0,pivot-1,key)<<endl;
	    }else{
	        cout<<binarySearch(arr,pivot+1,n-1,key)<<endl;
	    }
	}
	return 0;
}
