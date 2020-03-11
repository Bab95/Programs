#include <iostream>
using namespace std;

int main() {
	//code
	int t,n,sum;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>sum;
	    int dp[n+1][sum+1];
	    for(int i=1;i<=n;i++){
	        dp[i][0] = 1;
	    }
	    for(int i=0;i<=sum;i++){
	        dp[0][i] = 0;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	             if(j>=arr[i-1]){
	                int include = dp[i][j-arr[i-1]];
	                int exclude = dp[i-1][j];
	                dp[i][j] = include + exclude;
	            }else{
	                int exclude = dp[i-1][j];
	                dp[i][j] = exclude;
	            }
	        }
	    }
	    cout<<dp[n][sum]<<endl;

	}
	return 0;
}
