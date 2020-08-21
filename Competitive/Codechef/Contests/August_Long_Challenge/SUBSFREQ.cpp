/*10-Points*/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
const int m = 1000000007;
int _power(int a,int b){
    long long int x = (long int)a;
    long long int _p = 1;
    x = x % m;
    while(b > 0){
        if(b&1){
            _p = (_p*x)%m;
        }
        b = b>>1;
        x = (x*x)%m;
    }
    return _p;
}
using namespace std;
void solve(){
    int n;
    cin>>n;
    /*vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }*/
    for(int i=1;i<=n;++i){
        cout<<_power(2,n-i)<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
