#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
typedef unsigned long long int ulli;
typedef long long int ll;
typedef int64_t bigint;
using namespace std;
int64_t lcm(int64_t a,int64_t b){
    int64_t ans = (a*b)/__gcd(a,b);
    return ans;
}
void solve(){
    int64_t n,k,a,b;
    cin>>n>>a>>b>>k;
    int64_t appy = n/a;
    int64_t chef = n/b;
    int64_t common= n/lcm(a,b);
    //cout<<appy<<" "<<chef<<" "<<common<<endl;
    int64_t problems = appy + chef - 2*common;
    //cout<<problems<<endl;
    if(problems<k){
        cout<<"Lose"<<endl;
    }else{
        cout<<"Win"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
