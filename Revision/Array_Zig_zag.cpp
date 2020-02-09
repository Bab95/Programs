#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void my_sort(int arr[],int n){
    bool increasing = true;
    for(int i=0;i<n-1;i++){
        if(increasing&&arr[i+1]<arr[i]){
            swap(&arr[i],&arr[i+1]);
        }
        if(!increasing&&arr[i+1]>arr[i]){
            swap(&arr[i+1],&arr[i]);
        }
        increasing = !increasing;
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
	    my_sort(arr,n);
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
