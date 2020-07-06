#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  int a,b,c;
  int ans = 0;
  for(int i=0;i<n;++i){
    cin>>a>>b>>c;
    if(a+b+c>=2){
      ans++;
    }
  }
  cout<<ans<<endl;
}
int main(){
    solve();
}
