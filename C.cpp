#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int n_1s = 0;
  int ans = 0;
  for(int i=0;i<n;){
    int count = 0;
    if(arr[i]=='1'){
      n_1s++;
    }
    while(i<n&&arr[i]!='1'){
      count++;
      ++i;
    }
    ans+=count/(k+2);
  }
  if(n_1s==0){
    ans+=1;
    int count = s.length()-1;
    ans+=count/(k+2);
  }
  cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
