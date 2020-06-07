#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define speed ios::sync_with_stdio(0);cin.tie(0)
void solve(){
    string s;
    cin>>s;
    ull sum = 0;
    for(ull i=0;i<s.length();++i){
        sum += s[i]-'0';
    }
    if(sum<5&&s.length()>1){
        cout<<9-sum<<endl;
    }
    else{
        cout<<min(9-sum%9,sum%9)<<endl;
    }
}
int main(){
    int t;
    speed;
    cin>>t;
    while(t--){
        solve();
    }
}
