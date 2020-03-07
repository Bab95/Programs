#include <iostream>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001
int dp[MAX_SIZE][MAX_SIZE];
int weight[MAX_SIZE];
int value[MAX_SIZE];
int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t,n,w;
	cin>>t;
	while(t--){
	    cin>>n>>w;
	    for(int i=0;i<n;i++){
	        cin>>value[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>weight[i];
	    }
	    /*
	    for(int i=0;i<=t_weight;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0){
	                dp[i][j] = 0;
	            }else if(weight[j-1]<=i){
	                dp[i][j] = max(dp[i-weight[j-1]][j-1]+value[j-1],dp[i][j-1]);
	            }else{
	                dp[i][j] = dp[i][j-1];
	            }
	        }
	    }*/
	    int result = 0;
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=w;j++){
	            if(i==0||j==0){
	                dp[i][j] = 0;
	            }else if(weight[i-1]<=j){
	                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    result = max(result,dp[n][w]);
	    cout<<result<<endl;

	}
	return 0;
}
