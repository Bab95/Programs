/*
apply LCS on the same string as second string but keeping that when characters
are same index shouldn'y be the same.......
*/
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(str[i-1]==str[j-1]&&i!=j){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //printing string....
    string res;
    int i = 0;
    int j = 0;
    //backtrack the longest path...........
    while(i>0&&j>0){
      if(dp[i][j]==dp[i-1][j-1]+1){
        res.push_back(str[i-1]);
        i--;
        j--;
      }else if(dp[i][j]==dp[i-1][j]){
        i--;
      }else{
        j--;
      }
    }
    i = 0;
    j = res.length()-1;
    while(i<j){
      swap(res[i],res[j]);
      i++;
      j--;
    }
    cout<<res<<endl;
    cout<<dp[n][n]<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
