#include <iostream>
#define MAX_SIZE 21
using namespace std;
int max(int a,int b,int c){
    int tmp = (a>b)?a:b;
    return (tmp>c)?tmp:c;
}
int max1(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int mat[MAX_SIZE][MAX_SIZE];
	int t,n,m;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int dp[MAX_SIZE][MAX_SIZE];
	    for(int i=0;i<n;i++){
	        dp[i][0] = mat[i][0];
	    }
	    int up,right,down;
	    for(int j=1;j<m;j++){
	        for(int i=0;i<n;i++){
	            up = (i==0)?0:dp[i-1][j-1];
	            right = dp[i][j-1];
	            down = (i==n-1)?0:dp[i+1][j-1];
	            dp[i][j] = mat[i][j]+max(up,right,down);
	        }
	    }
	    int ans = dp[0][m-1];
	    for(int i=1;i<n;i++){
	        ans = max1(dp[i][m-1],ans);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
