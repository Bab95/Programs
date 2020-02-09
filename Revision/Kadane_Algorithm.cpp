#include <iostream>
#include <limits.h>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
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
	    int current_sum = arr[0];
	    int max_so_far =current_sum;
	    for(int i=1;i<n;i++){
	        current_sum = max(current_sum+arr[i],arr[i]);
	        max_so_far = max(current_sum,max_so_far);
	    }
	    cout<<max_so_far<<endl;
	}
	return 0;
}
