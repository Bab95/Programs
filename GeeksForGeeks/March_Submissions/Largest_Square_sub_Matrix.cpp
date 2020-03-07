#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t,m,n;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    vector<vector<int> > matrix(m,vector<int>(n,0));
	    vector<vector<int> > dp(m,vector<int>(n,0));
	    int max_square = 0;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    for(int i=0;i<m;i++){
	        dp[i][0] = matrix[i][0];
	    }
	    for(int j=1;j<n;j++){
	        dp[0][j] = matrix[0][j];
	    }
	    for(int i=1;i<m;i++){
	        for(int j=1;j<n;j++){
	            if(matrix[i][j]){
	                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
	            }else{
	                dp[i][j] = 0;
	            }
	        }
	    }
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            max_square= max(dp[i][j],max_square);
	        }
	    }
	    cout<<max_square<<endl;
	}
	return 0;
}
