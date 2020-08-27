#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
const int MAX = 1e5+1;

using namespace std;
void solve(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b;
    }
    int ans = 0;
    if(n<=5){
        cout<<n<<endl;
        return;
    }
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;++i){
        if(i<=5){
            dp[i] = i;
        }else{
            dp[i] = i + dp[i/2];
        }
    }
    cout<<dp[n]<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
