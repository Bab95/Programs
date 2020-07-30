/*
  *author: Captain_Levi*

*/
#define _CRT_SECURE_NO_WARNINGS

typedef __int128_t bint;
#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ulli;
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
  vector<int> arr(n);
  input_vector(arr);
  ll ans = 0;
  for(int i=1;i<arr.size();++i){
    if(arr[i]<arr[i-1]){
      ans += (ll)(arr[i-1]-arr[i]);
      arr[i] = arr[i-1];
    }
  }
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
