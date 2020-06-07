#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<int> corresponding_val(n);
    int ans = 0;
    for(int i=n-1;i>=0;--i){
        corresponding_val[i] = arr[i]+i;
        ans = max(ans,corresponding_val[i]);
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
