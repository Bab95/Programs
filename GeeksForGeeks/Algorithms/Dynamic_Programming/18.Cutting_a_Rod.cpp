#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t;
	cin>>t;
	int n,x,y,z;
	while(t--){
	    cin>>n;
	    cin>>x>>y>>z;
	    int dp[n+1];
	    memset(dp,-1,sizeof(dp));
	    dp[0] = 0;
	    for(int i=0;i<n;i++){
	        if(dp[i]!=-1){
	            if(i+x<=n){
	                dp[i+x] = max(dp[i+x],dp[i]+1);
	            }
	            if(i+y<=n){
	                dp[i+y] = max(dp[i+y],dp[i]+1);
	            }
	            if(i+z<=n){
	                dp[i+z] = max(dp[i+z],dp[i]+1);
	            }
	        }
	    }
	    /*for(int i=1;i<=n;i++){
	        cout<<dp[i]<<" ";
	    }
	    cout<<endl;*/
	    cout<<dp[n]<<endl;
	}
	return 0;
}
