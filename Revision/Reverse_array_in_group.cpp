#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
	//code
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int index = 0;
	    while(index<n){
	        int start = index;
	        int end = ((index+k-1)<n)?(index+k-1):(n-1);
	        while(start<end){
	            swap(&arr[start],&arr[end]);
	            start++;
	            end--;
	        }
	        index = index+k;
	    }
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
