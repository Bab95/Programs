#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  char a1,a2,a3;
  a1 = (360%n==0)?'y':'n';
  a2 = (n<=360)?'y':'n';
  a3 = (n<=26)?'y':'n';
  cout<<a1<<" "<<a2<<" "<<a3<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
