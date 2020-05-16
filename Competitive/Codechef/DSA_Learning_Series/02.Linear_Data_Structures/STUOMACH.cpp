#include <iostream>
#include <vector>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
ll min(ll a,ll b){
    return a<b?a:b;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> s(n);
    fo(i,0,n-1){
      cin>>s[i];
    }
    vector<ll> m(n,0);
    m[0] = s[0];
    ll ans = m[0];
    for(int i=1;i<n;++i){
      m[i] = min(m[i-1],s[i]);
      ans+=m[i];
    }
    cout<<ans<<endl;

}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
