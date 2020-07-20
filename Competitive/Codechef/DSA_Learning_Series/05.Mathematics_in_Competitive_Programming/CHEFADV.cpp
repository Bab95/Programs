#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ulli;
typedef int64_t bi;
#define Y "Chefirnemo"
#define N "Pofik"
void solve(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    if(n==1&&m==1){
        cout<<Y<<endl;
        return;
    }
    //without sharechat....
    ll reqn = n-1;
    ll reqm = m-1;
    if(reqn<0||reqm<0){
        cout<<N<<endl;
        return;
    }
    if(reqn%x==0&&reqm%y==0){
        cout<<Y<<endl;
        return;
    }
    //sharechat effect....
    reqn = reqn-1;
    reqm = reqm-1;
    if(reqn<0||reqm<0){
        cout<<N<<endl;
        return;
    }
    if(reqn%x==0&&reqm%y==0){
        cout<<Y<<endl;
        return;
    }
    cout<<N<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
