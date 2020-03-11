#include <iostream>
using namespace std;

int main() {
	//code
	int t,n,w;
	cin>>t;
	while(t--){
	    cin>>n>>w;
	    int wt[n];
	    int cost[n];
	    for(int i=0;i<n;i++){
	        cin>>cost[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>wt[i];
	    }
	    int dp[n+1][w+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=w;j++){
	            if(i==0||j==0){
	                dp[i][j] = 0;
	            }
	            else if(wt[i-1]<=j){
	                //int include = (i>=1)?(dp[i-1][j-wt[i]]+cost[i]):0;
	                //int exclude = (i>=0)?dp[i-1][j]:0;
	                int include = dp[i-1][j-wt[i-1]]+cost[i-1];
	                int exclude = dp[i-1][j];
	                dp[i][j] = max(include,exclude);
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }

	    cout<<dp[n][w]<<endl;
	}
	return 0;
}
