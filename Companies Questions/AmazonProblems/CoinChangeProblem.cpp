#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	int n,m;
	while(t--){
	    cin>>m;
	    int coins[m];
	    for(int i=0;i<m;i++){
	        cin>>coins[i];
	    }
	    cin>>n;
	    int dp[n+1][m];
	    for(int i=0;i<m;i++){
	        dp[0][i] = 1;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<m;j++){
	            int include = (coins[j]<=i)?dp[i-coins[j]][j]:0;
	            int exclude = (j>=1)?dp[i][j-1]:0;

	            dp[i][j] = include + exclude;
	        }
	    }
	    cout<<dp[n][m-1]<<endl;
	}
	return 0;
}
