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
  string s;
  cin>>s;
  int len = s.length();
  unordered_map<char,int> mmap;
  for(auto &c : s){
    mmap[c] += 1;
  }
  bool odd_flag = false;
  if(len%2==1){
    //odd so one single character allowed...
    odd_flag = true;
  }
  int odd_count = 0;
  char odd_char = '#';
  for(auto it=mmap.begin();it!=mmap.end();++it){
    if(it->second%2==1){
      if(odd_flag&&odd_count==0){
        odd_count += 1;
        odd_char = it->first;
      }else{
        cout<<"NO SOLUTION"<<endl;
        return;
      }
    }
  }
  if(odd_flag){
    s[len/2] = odd_char;
    mmap[odd_char] -= 1;
  }
  int l = 0;
  int r = len-1;
  for(auto it=mmap.begin();it!=mmap.end();++it){
    while(it->second>0){
      s[l] = it->first;
      s[r] = it->first;
      it->second -= 2;
      ++l;
      --r;
    }
  }
  cout<<s<<endl;
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
