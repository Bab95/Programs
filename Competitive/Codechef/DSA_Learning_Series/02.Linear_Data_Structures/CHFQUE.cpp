
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
#define mod 1000000007
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0;i < n;++i) {
		cin >> arr[i];
	}
	stack<int> stk;
	ll ans = 1;
	for (int i = 0;i < n;++i) {
		while (!stk.empty() && arr[i] < arr[stk.top()]) {
			ll chaos = i - stk.top() + 1;
			stk.pop();
			ans *= chaos;
			ans = ans%mod;
		}
		stk.push(i);
	}
	cout << ans << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
