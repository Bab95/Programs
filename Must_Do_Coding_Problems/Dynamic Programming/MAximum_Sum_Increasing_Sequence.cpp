#include <iostream>
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
	    int *arr = new int[n];
	    int *sum = new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum[i] = arr[i];
	    }
	    int result = arr[0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]&&sum[j]+arr[i]>sum[i]){
	                sum[i] = sum[j]+arr[i];
	                result = max(result,sum[i]);
	            }
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
