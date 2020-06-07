#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int count = 0;
    int n = s.length();
    vector<bool> visited(n,false);
    for(int i=1;i<n;++i){
        if(s[i]!=s[i-1]&&!visited[i-1]){
            count++;
            visited[i] = true;
            visited[i-1] = true;
        }
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
