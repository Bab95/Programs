#include <bits/stdc++.h>
using namespace std;
int maxRodValue(vector<int>& prices,int len){
    vector<int> dp(len+1,INT_MIN);
    dp[0] = 0;
    for(int i=1;i<=len;++i){
        int max_val = INT_MIN;
        for(int j=0;j<i;++j){
            max_val = max(max_val,prices[j]+dp[i-j-1]);
        }
        dp[i] = max_val;
    }
    return  dp[len];
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;++i){
        cin>>prices[i];
    }
    cout<<maxRodValue(prices,n)<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
        solve();
    }
}