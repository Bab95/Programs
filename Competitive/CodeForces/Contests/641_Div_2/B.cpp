#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <string.h>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
#define M 1000000
using namespace std;
void precomute(unordered_map<int,vector<int> >& mmap){
	int n = M;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sqrt(i);++j){
			if(i%j==0){
				if(i/j==j){
					mmap[i].push_back(j);
				}else{
					mmap[i].push_back(j);
					mmap[i].push_back(n/j);
				}
			}
		}
		sort(mmap[i].begin(),mmap[i].end());
	}
}
void solve(unordered_map<int,vector<int> >& mmap) {
	ll n;
	cin>>n;
	vector<ll> arr(n+1);
	arr[0] = INT_MAX;
	fo(i,1,n){
		cin>>arr[i];
	}

	vector<int> dp(n+1,1);
	for(int i=2;i<=n;i++){
		for(auto it=mmap[i].begin();it!=mmap[i].end();++it){
			if(*it<i&&arr[*it]<i&&dp[i]<dp[*it]+1){
				dp[i] = dp[*it]+1;
			}
		}
	}
	int ans = dp[1];
	for(int i=1;i<=n;++i){
		if(dp[i]>ans){
			ans = dp[i];
		}
	}
	cout<<ans<<endl;
}

int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	unordered_map<int,vector<int> > mmap;
	precomute(mmap);
	while (t--) {
		solve(mmap);
	}
	return 0;
}
