#include <iostream>
#include <vector>
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
	    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	    int dp[10][n+1];
	    //boundary case 1 rs
	    for(int i=0;i<=n;i++){
	        dp[0][i] = i;
	    }
	    for(int i=1;i<10;i++){
	        for(int j=0;j<=n;j++){
	            if(j>=coins[i]){
	                dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    //printing
	    int i = 9;
	    int j = n;
	    while(i>=0&&j>0){
	        if(dp[i][j]==dp[i-1][j])
	            i--;
	        else{
	            cout<<coins[i]<<" ";
	            j = j-coins[i];
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
