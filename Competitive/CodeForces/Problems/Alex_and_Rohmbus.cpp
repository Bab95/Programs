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
#include <string>
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
int dp[101];
void precalculate(){
	memset(dp,0,sizeof(dp));
	dp[1] = 1;
	for(int i=2;i<=100;++i){
		dp[i] = dp[i-1] + 4*(i-1);
	}
}
void solve(){
	int n;
	cin>>n;
	cout<<dp[n]<<endl;
}
int main(){
	precalculate();
	solve();
	return 0;
}
