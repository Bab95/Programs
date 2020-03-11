
#include <iostream>
#include <vector>
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
	    vector<int> dp(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        dp[i] = arr[i];
	    }

	    int res = -1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]&&dp[i]<dp[j]*arr[i]){
	                dp[i] = dp[j] * arr[i];
	                //res = max(dp[i],res);
	            }
	        }

	    }
	    for(int i=0;i<n;i++){
	        res = max(res,dp[i]);
	    }
	    cout<<res<<endl;

	}
	return 0;
}
