#include <iostream>
#include <string>
using namespace std;
int min(int a,int b,int c){
    int tmp = a<b?a:b;
    return tmp<c?tmp:c;
}
int main() {
	//code
	int t;
	int m,n;
	cin>>t;
	while(t--){
	   cin>>m>>n;
	   string s1,s2;
	   cin>>s1;
	   cin>>s2;
	   int dp[m+1][n+1];
	   for(int i=1;i<=n;i++){
	       dp[0][i] = i;
	   }
	   for(int i=1;i<=m;i++){
	       dp[i][0] = i;
	   }
	   dp[0][0] = 0;
	   for(int i=1;i<=m;i++){
	       for(int j=1;j<=n;j++){
	           if(s1[i-1]==s2[j-1]){
	               dp[i][j] = dp[i-1][j-1];
	           }else{
	               dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
	           }
	       }
	   }
	   cout<<dp[m][n]<<endl;
	}
	return 0;
}
