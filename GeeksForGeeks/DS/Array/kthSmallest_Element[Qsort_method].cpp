#include <iostream>
#include <limits.h>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
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
int randompartition(int arr[],int start,int end){
    int n = end-start+1;
    int pivot = rand()%n;
    swap(&arr[start+pivot],&arr[end]);
    return partition(arr,start,end);
}
int quicksort(int arr[],int start,int end,int k){
    if(k>0&&k<=end-start+1){
        int pivot = randompartition(arr,start,end);
        if(pivot-start==k-1){
            return arr[pivot];
        }
        else if(pivot-start>k-1){
            return quicksort(arr,start,pivot-1,k);
        }else if(pivot-start<k-1){
            return quicksort(arr,pivot+1,end,k-(pivot-start+1));
        }
    }
    return INT_MAX;
}
int main() {
	//code
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    cout<<quicksort(arr,0,n-1,k)<<endl;
	}
	return 0;
}
