#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(int i=n-1;i>=0;){
        ans += arr[i];
        --i;
        if(i>=0){
            ans+=arr[i];
            i--;
        }
        i = i-2;
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
