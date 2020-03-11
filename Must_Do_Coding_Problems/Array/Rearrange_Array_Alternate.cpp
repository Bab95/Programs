#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
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
	int t;
	cin>>t;
	int n;
	while(t--){
	    cin>>n;
	    int *arr = new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    //quicksort(arr,0,n-1);
	    /*cout<<"after sorting"<<endl;
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;*/
	    int start=0,end=n-1;
	    //cout<<"answer"<<endl;
	    while(start<end){
	        cout<<arr[end]<<" "<<arr[start]<<" ";
	        end--;
	        start++;
	    }
	    if(n%2!=0){
	        cout<<arr[end];
	    }
	    cout<<endl;
	}
	return 0;
}
