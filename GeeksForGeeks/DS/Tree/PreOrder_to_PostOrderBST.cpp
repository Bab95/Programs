#include <iostream>
using namespace std;
int findIndex(int arr[],int val,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
void postOrder(int in[],int pre[],int n){
    int index = findIndex(in,pre[0],n);
    if(index!=0){
        postOrder(in,pre+1,index);
    }
    if(index!=n-1){
        postOrder(in+index+1,pre+index+1,n-index-1);
    }
    cout<<pre[0]<<" ";
}
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
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int in[n],pre[n];
	    for(int i=0;i<n;i++){
	        cin>>pre[i];
	        in[i] = pre[i];
	    }
	    quicksort(in,0,n-1);
	    /*for(int i=0;i<n;i++){
	        cout<<in[i]<<" ";
	    }
	    cout<<endl;*/
	    postOrder(in,pre,n);
	    cout<<endl;
	}
	return 0;
}
