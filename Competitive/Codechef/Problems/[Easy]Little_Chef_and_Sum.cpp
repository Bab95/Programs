#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    int n;
    cin>>n;
    vector<ll> arr(n),prefix(n,0),suffix(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    prefix[0] = arr[0];
    for(int i=1;i<n;++i){
        prefix[i] = prefix[i-1]+arr[i];
    }
    suffix[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1]+arr[i];
    }
    ll prev = prefix[0]+suffix[0];
    int ans = 0;
    for(int i=1;i<n;++i){
        if(prefix[i]+suffix[i]<prev){
            prev = prefix[i] + suffix[i];
            ans = i;
        }
    }
    cout<<ans+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
