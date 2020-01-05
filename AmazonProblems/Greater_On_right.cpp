#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
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
	    int ans[n];
	    int max_so_far = -1;
	    //ans[n-1] = -1;
	    for(int i=n-1;i>=0;i--){
	        ans[i] = max_so_far;
	        max_so_far = max(max_so_far,arr[i]);
	    }
	    for(int i=0;i<n;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
