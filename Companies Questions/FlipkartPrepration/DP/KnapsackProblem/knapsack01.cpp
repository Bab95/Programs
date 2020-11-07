#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int>& weight,vector<int>& value,int w){
    int n = weight.size();
    vector<vector<int> > dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=w;++j){
            int include=0,exclude=0;
            if(weight[i-1]<=j){
                include = dp[i-1][j-weight[i-1]] + value[i-1];
                exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
void solve(){
    
    int n,w;
    cin>>n>>w;
    vector<int> weight(n),value(n);
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    for(int i=0;i<n;++i){
        cin>>weight[i];
    }
    cout<<knapsack(weight,value,w)<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
        solve();
    }
}