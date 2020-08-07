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
  int n,x;
  cin>>n;
  vector<int> ss(n);
  for(int i=0;i<n;++i){
    cin>>ss[i];
  }
  sort(ss.begin(),ss.end());
  int count = 0;
  for(int i=0;i<ss.size();){
    int current = ss[i];
    while(i<ss.size()&&current==ss[i]){
      ++i;
    }
    count++;
  }
  cout<<count<<endl;
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
