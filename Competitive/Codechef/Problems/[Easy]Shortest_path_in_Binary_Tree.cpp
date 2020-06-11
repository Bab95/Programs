#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ulli;
void solve(){
    ll a,b;
    cin>>a>>b;
    int d1 = 0,d2 = 0;
    while(true){
        if(a==b){
            cout<<d1+d2<<endl;
            return;
        }else if(a>b){
            a = a/2;
            d1++;
        }else if(b>a){
            b = b/2;
            d2++;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
