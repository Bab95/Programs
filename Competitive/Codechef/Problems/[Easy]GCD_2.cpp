#include <bits/stdc++.h>
using namespace std;
int mod(string& b,int a){
  int ans = 0;
  for(int i=0;i<b.length();++i){
    ans = (ans*10+(int)b[i]-'0')%a;
  }
  return ans;
}
int find_GCD(int a,int b){
  if(b==0){
    return a;
  }
  return find_GCD(b,a%b);
}

void solve(){
  string b;
  int a;
  cin>>a;
  cin>>b;
  if(a==0){
      cout<<b<<endl;
  }else if(b.compare("0")==0){
      cout<<a<<endl;
  }else{
    int ans = find_GCD(a,mod(b,a));
    cout<<ans<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
