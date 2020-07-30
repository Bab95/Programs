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
  if(n==1){
    cout<<1<<endl;
    return;
  }
  if(n<=3){
    cout<<"NO SOLUTION"<<endl;
  }else{
    if(n%2==0){
      for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
      }
      for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
      }
      cout<<endl;
    }else{
      for(int i=n-1;i>=1;i-=2){
        cout<<i<<" ";
      }
      for(int i=n;i>=1;i-=2){
        cout<<i<<" ";
      }
      cout<<endl;
    }
  }
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
