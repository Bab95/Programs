#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long int n;
  cin>>n;
  long long int ans = 0;
  if(n%2==0){
    ans = n/2;
    ans = ans*(n+1);
    ans+=n;
  }else{
    ans = (n+1)/2;
    ans = ans*n;
    ans+=n;
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
