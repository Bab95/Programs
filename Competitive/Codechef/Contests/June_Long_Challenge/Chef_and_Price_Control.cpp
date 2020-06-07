#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    int total = 0;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        total+=(arr[i]);
    }
    int revenue = 0;
    for(int i=0;i<n;++i){
        revenue+=min(arr[i],k);
    }
    cout<<total-revenue<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
