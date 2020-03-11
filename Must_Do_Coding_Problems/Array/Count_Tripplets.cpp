#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int arr[],int start,int end){
    int pivot = arr[end];
    int i = start;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[end]);
    return i;
}
void quicksort(int arr[],int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    quicksort(arr,0,n-1);
	    /*for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;*/
	    int l,r;
	    int res = 0;
	    for(int i=n-1;i>=2;i--){
	        l = 0;
	        r = i;
	        while(l<r){
	            if(arr[l]+arr[r]==arr[i]){
	                res++;
	                l++;
	                r--;
	            }else if(arr[l]+arr[r]>arr[i]){
	                r--;
	            }else{
	                l++;
	            }
	        }
	    }
	    if(res==0){
	        res = -1;
	    }
	    cout<<res<<endl;
	}
	return 0;
}
