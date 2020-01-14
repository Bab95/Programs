#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void arrange(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=-1&&arr[i]!=i){
            int x = arr[i];
            while(arr[x]!=-1&&arr[x]!=x){
                int y = arr[x];
                arr[x] = x;
                x = y;
            }
            arr[x] = x;
            if(arr[i]!=i){
                arr[i] = -1;
            }
        }
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
	    arrange(arr,n);
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
