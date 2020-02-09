#include <iostream>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n],left[n],right[n];
	    for(int i=0;i<n;i++){
	         cin>>arr[i];
	    }
	    left[0] = arr[0];
	    for(int i=1;i<n;i++){
	        left[i] = max(left[i-1],arr[i]);
	    }
	    right[n-1] = arr[n-1];
	    for(int i=n-2;i>=0;i--){
	        right[i] = max(right[i+1],arr[i]);
	    }
	    int water = 0;
	    for(int i=0;i<n;i++){
	        water = water+min(left[i],right[i])-arr[i];
	    }
	    cout<<water<<endl;
	}
	return 0;
}
