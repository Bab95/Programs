#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int ans = 2;
    for(int i=1;i<s.length();++i){
        //cout<<s[i-1]<<"-- vs --"<<s[i]<<" :";
        if(s[i]==s[i-1]){
            ans += 1;
            //cout<<0<<endl;
        }else{
            int diff = s[i]-s[i-1];
            if(diff<0){
                diff = 26+diff;
            }
            ans+=diff;
            ++ans;
            //cout<<diff<<endl;
        }
    }
    if(ans>11*s.length())
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
