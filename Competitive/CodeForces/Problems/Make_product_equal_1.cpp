#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr,int n){
	fo(i,0,n-1){
		cin>>arr[i];
	}
}
int sign_of(int a){
	if(a<0){
		return -1;
	}
	return 1;
}
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	input(arr,n);
	int sign = 1;
	int64_t ans = 0;
	int zeros=0;
	for(int i=0;i<n;++i){
		sign = sign*sign_of(arr[i]);
		int64_t current = (int64_t)abs(arr[i]);
		if(current==1){
			continue;
		}else if(current==0){
			ans += 1;
			zeros++;
		}else{
			ans += (int64_t)abs(current-1);
		}
	}
	if(sign==-1&&zeros==0){
		ans += 2;
	}
	cout<<ans<<endl;
}
int main(){
	solve();
	return 0;
}
