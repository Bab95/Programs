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
	ll x,y;
	cin>>y>>x;
	ll ans;
	ll _0x;
	if(x>=y){
		if(x%2==1){
			_0x = x*x;
			ans = _0x - y + 1;
		}else{
			_0x = (x-1)*(x-1) + 1;
			ans = _0x + y -1;
		}
	}else{
		if(y%2==0){
			_0x = y*y;
			ans = _0x - x + 1;
		}else{
			_0x = (y-1)*(y-1) + 1;
			ans = _0x + x - 1;
		}
	}
	cout<<ans<<"\n";
}
void solve_t(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
int main(){
  //solve();
  solve_t();
  return 0;
}
