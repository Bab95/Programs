#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}
int main() {
	//code
	int t,m,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    m = n;
	    vector<vector<int> > matrix(m,vector<int>(n,0));
	    vector<vector<int> > dp(m,vector<int>(n,0));
	    int max_square = 0;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    for(int i=0;i<n;i++){
	        dp[0][i] = matrix[0][i];
	    }
	    for(int i=1;i<m;i++){
	        for(int j=0;j<n;j++){
	            int a = (j==0)?INT_MIN:dp[i-1][j-1];
	            int b = (j==n-1)?INT_MIN:dp[i-1][j+1];
	            int c = dp[i-1][j];
	            dp[i][j] = matrix[i][j] + max(max(a,b),c);
	        }
	    }
	    /*for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cout<<dp[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/
	    int result = dp[m-1][0];
	    for(int i=1;i<n;i++){
	        result = max(result,dp[m-1][i]);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
