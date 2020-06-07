#include <bits/stdc++.h>
using namespace std;
void solve(){
    int l;
    cin>>l;
    getchar();
    string s;
    cin>>s;
    long long int count_1;
    for(int i=0;i<s.length();++i){
        if(s[i]=='1'){
            count_1++;
        }
    }
    long long int ans = 0;
    ans = (count_1*(count_1+1))/2;
    cout<<ans<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
