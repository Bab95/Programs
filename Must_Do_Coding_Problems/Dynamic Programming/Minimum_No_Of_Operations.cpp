#include <iostream>
#include <limits.h>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int dp[n+1];
	    //memset(dp,INT_MAX,sizeof(dp));
	    for(int i=0;i<=n;i++){
	        dp[i] = INT_MAX;
	    }
	    dp[0] = 0;
	    dp[1] = 1;
	    for(int i=0;i<=n;i++){
	        if(dp[i]!=INT_MAX){
	            if(2*i<=n){
	                dp[2*i] = min(dp[2*i],dp[i]+1);
	            }
	            if(i+1<=n){
	                dp[i+1] = min(dp[i+1],dp[i]+1);
	            }
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
