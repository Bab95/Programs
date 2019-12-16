#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int arr[],int start,int end){
    int pivot = arr[start];
    int i = start+1;
    for(int j=start+1;j<=end;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i-1],&arr[start]);
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
	int t;
	cin>>t;
	int n;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int index = -1;
	    for(int i=n-2;i>=0;i--){
	        if(arr[i]<arr[n-1]){
	            swap(&arr[i],&arr[n-1]);
	            index = i;
	            break;
	        }
	    }
	    //cout<<"index: "<<index<<endl;
	    quicksort(arr,index+1,n-1);
	        for(int i=0;i<n;i++){
	            cout<<arr[i]<<" ";
	        }
	        cout<<endl;
	}
	return 0;
}
