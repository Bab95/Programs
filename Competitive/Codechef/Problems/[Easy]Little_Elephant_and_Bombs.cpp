#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;++i){
    if(s[i]=='1'){
      if(i>0){
        s[i-1] = '2';
      }
      s[i] = '2';
      if(i<n-1&&s[i+1]!='1'){
        s[i+1] = '2';
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;++i){
    if(s[i]=='0'){
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
  return 0;
}
