#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n,t;
    cin>>n>>t;
    vector<pair<ll,ll> > arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;++i){
        cin>>arr[i].second;
    }
    ll ans = (t/arr[0].first)*arr[0].second;
    for(int i=1;i<n;++i){
        ll current = (t/arr[i].first)*arr[i].second;
        ans = max(ans,current);
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
