/*
  *author: Captain_Levi*

*/
#define _CRT_SECURE_NO_WARNINGS

typedef __int128_t bint;
#include <bits/stdc++.h>
typedef long int li;
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
const int m = 1e9+7;
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
ll power_exponent(ll a,int b){
  li result = 1;
  a = a%m;
  while(b>0){
    if(b&1){
      result = result*a %m;
    }
    b = b>>1;
    a = a*a%m;
  }
  return result;
}
void solve(){
  int n;
  cin>>n;
  ll ans = power_exponent(2,n);
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
