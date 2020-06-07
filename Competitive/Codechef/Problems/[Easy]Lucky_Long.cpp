#include <bits/stdc++.h>
using namespace std;
void solve(){
    string num;
    cin>>num;
    int ans = 0;
    for(int i=0;i<num.length();++i){
        if(num[i]=='4'||num[i]=='7'){
            continue;
        }else{
            ans++;
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
