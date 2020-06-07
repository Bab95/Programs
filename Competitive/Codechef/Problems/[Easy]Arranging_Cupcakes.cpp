#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  int high = (int)sqrt(n);
  int low = 1;
  int ans = INT_MAX;
  for(int i=low;i<=high;++i){
      if(n%i==0){
          int a = i;
          int b = n/i;
          int tmpans = abs(a-b);
          ans = min(ans,tmpans);
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
}
#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  int high = (int)sqrt(n);
  int low = 1;
  int ans = INT_MAX;
  for(int i=low;i<=high;++i){
      if(n%i==0){
          int a = i;
          int b = n/i;
          int tmpans = abs(a-b);
          ans = min(ans,tmpans);
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
}
