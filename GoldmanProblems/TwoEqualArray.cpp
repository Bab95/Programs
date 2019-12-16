#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int partition(int arr[],int start,int end){
    int i = start+1;
    int pivot = arr[start];
    for(int j=start+1;j<=end;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[start],&arr[i-1]);
    return i-1;
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
	    int arr[n],brr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int j=0;j<n;j++){
	        cin>>brr[j];
	    }
	    quicksort(arr,0,n-1);
	    quicksort(brr,0,n-1);
	    bool flag = true;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=brr[i]){
	            flag = false;
	            break;
	        }
	    }
	    if(!flag){
	        cout<<"0"<<endl;
	    }else{
	        cout<<"1"<<endl;
	    }
	}
	return 0;
}
