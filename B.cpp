#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  int even_at_odd = 0;
  int odd_at_even = 0;
  for(int i=0;i<n;++i){
    if(arr[i]%2==i%2){
      continue;
    }else{
      if(i%2==1&&arr[i]%2==0){
        even_at_odd++;
      }else{
        odd_at_even++;
      }
    }
  }
  if(odd_at_even!=even_at_odd){
    cout<<-1<<endl;
  }else{
    cout<<odd_at_even<<endl;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
