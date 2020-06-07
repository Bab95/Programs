#include <bits/stdc++.h>
using namespace std;
void solve(){
  double l,d,s,c;
  string win = "ALIVE AND KICKING";
  string loss = "DEAD AND ROTTING";
  cin>>l>>d>>s>>c;
  double likes = s*pow(c+1,d-1);
  if(likes>=l){
    cout<<win<<endl;
  }else{
    cout<<loss<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
