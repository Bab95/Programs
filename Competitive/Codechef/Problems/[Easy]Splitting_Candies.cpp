#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long int n,k;
  cin>>n>>k;
  if(n==0){
    cout<<0<<" "<<0<<endl;
    return;
  }
  if(k==0){
    cout<<0<<" "<<n<<endl;
    return;
  }
  cout<<n/k<<" "<<n%k<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
