#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long int n;
  cin>>n;
  int x;
  for(int i=0;i<n;++i){
    cin>>x;
  }
  long long int ans;
  if(n%2==0){
    ans = n/2;
    ans = ans*(n-1);
  }else{
    ans = (n-1)/2;
    ans = ans*n;
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
