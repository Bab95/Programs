#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n;
    scanf("%lld",&n);
    vector<ll> arr(n),left(n),right(n);
    for(ll i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    left[0] = arr[0];
    for(int i=1;i<n;++i){
        left[i] = min(left[i-1],arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],arr[i]);
    }
    /*
    for(int i=0;i<n;++i){
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i){
        cout<<right[i]<<" ";
    }
    cout<<endl;
    */
    ll diff = INT_MIN;
    for(int i=0;i<n;++i){
        diff = max(diff,right[i]-left[i]);
    }
    if(diff<=0){
        cout<<"UNFIT"<<endl;
    }else{
        printf("%lld\n",diff);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
