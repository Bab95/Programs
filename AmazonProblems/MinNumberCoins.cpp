#include <iostream>
#include <limits.h>
using namespace std;
int min(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t;
	cin>>t;
	int N,k;
	while(t--){
	    cin>>N>>k;
	    int arr[k];
	    for(int i=0;i<k;i++){
	        cin>>arr[i];
	    }
	    int dp[N+1];
	    for(int i=0;i<=N;i++){
	        dp[i] = INT_MAX;
	    }
	    dp[0] = 0;
	    for(int i=1;i<=N;i++){
	        for(int j=0;j<k;j++){
	            if(arr[j]<=i){
	                int subres = dp[i-arr[j]];
	                if(subres!=INT_MAX&&subres+1<dp[i]){
	                    dp[i] = subres+1;
	                }
	            }
	        }
	    }
	    /*for(int i=0;i<=N;i++){
	        cout<<dp[i]<<" ";
	    }
	    cout<<endl;*/
	    int ans = -1;
	    ans = (dp[N]==INT_MAX)?-1:dp[N];
	    cout<<ans<<endl;
	}
	return 0;
}
