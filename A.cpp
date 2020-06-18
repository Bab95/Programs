#include <bits/stdc++.h>
using namespace std;
void solve(){
  string s;
  cin>>s;
  string ans;
  for(int i=0;i<s.length();i+=2){
    ans.push_back(s[i]);
  }
  ans.push_back(s[s.length()-1]);
  cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
