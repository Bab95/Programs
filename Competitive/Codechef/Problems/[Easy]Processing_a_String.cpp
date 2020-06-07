#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int ans = 0;
    for(int i=0;i<s.length();++i){
        if(s[i]>='0'&&s[i]<='9'){
            ans+=(s[i]-'0');
        }
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
