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
using namespace std;
void solve() {
	ll n, k;
	cin >> n >> k;
	if (n == 2) {
		cout << k*n - 1 << endl;
		return;
	}
	ll ans = 0;
	int i = 0;
	while (true) {
		if (k / (ll)pow(n, i) == 0) {
			break;
		}
		else {
			ans += k / (ll)pow(n, i);
		}
		++i;
	}
	//cout << i << endl;
	//cout << "Debug" << ans << endl;
	ans = ans / n + k;
	if (ans%n == 0) {
		cout << ans + 1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*1999999999
1999999993*/
