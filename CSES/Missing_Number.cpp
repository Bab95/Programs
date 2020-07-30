/*
  *author: Captain_Levi*

*/
#define _CRT_SECURE_NO_WARNINGS
typedef long long int ll;
typedef unsigned long long int ulli;
#include <bits/stdc++.h>

using namespace std;
template <typename T>
void input_vector(vector<T>& arr){
  for(int i=0;i<arr.size();++i){
    cin>>arr[i];
  }
}
template <typename T>
void print(vector<T>& arr){
  for(int i=0;i<arr.size();++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void solve(){
  int n;
  cin>>n;
  vector<int> arr(n-1);
  input_vector(arr);
  int _xor = 0;
  for(int i=0;i<arr.size();++i){
    _xor ^= arr[i];
  }
  int ans = 0;
  for(int i=1;i<=n;++i){
    ans ^= i;
  }
  ans = ans^_xor;
  cout<<ans<<endl;
}
void solve_t(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
int main(){
  solve();
  //solve_t();
  return 0;
}
