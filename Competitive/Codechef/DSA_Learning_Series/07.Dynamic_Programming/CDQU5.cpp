#include <bits/stdc++.h>
#define mod 1000000009
#define MAX_SIZE 1000001
#define endl "\n"
using namespace std;
long int dp[MAX_SIZE];
int last_n = -1;
void calculate(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<MAX_SIZE;++i){
        dp[i] = dp[i-2] + dp[i-3];
        if(dp[i]>=mod){
            dp[i] = dp[i]%mod;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
}
int main(){
    calculate();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
