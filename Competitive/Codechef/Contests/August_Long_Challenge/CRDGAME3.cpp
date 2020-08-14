#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int c,r;
    cin>>c>>r;
    int _c = c/9;
    if(c%9!=0){
        _c++;
    }
    int _r = r/9;
    if(r%9!=0){
        _r++;
    }
    if(_c<_r){
        cout<<0<<" "<<_c<<endl;
    }else{
        cout<<1<<" "<<_r<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
