/*
  *author: Captain_Levi*

*/
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
typedef int64_t bint;
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
template <typename T>
void print(vector<T>& arr){
  for(int i=0;i<arr.size();++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void solve(){
  ll n;
  cin>>n;
  vector<ll> ans;
  while(n!=1){
    ans.push_back(n);
    if(n%2==0){
      n /= 2;
    }else{
      n = 3*n + 1;
    }
  }
  ans.push_back(1);
  print(ans);
}
int main(){
  solve();
  //solve_t();
  return 0;
}
