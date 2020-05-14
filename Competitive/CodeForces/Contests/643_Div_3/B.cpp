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
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (int i = 0;i<n;++i) {
		cin >> a[i];
	}
	for (int i = 0;i<n;++i) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll asum = a[0];
	for (int i = 1;i<n;++i) {
		asum += a[i];
	}
	ll ai = 0;
	ll bi = n - 1;
	for (int i = 0;i<k;++i) {
		if (asum - a[ai] + b[bi]>asum) {
			asum = asum - a[ai] + b[bi];
			ai++;
			bi--;
		}
		else {
			break;
		}
	}
	cout << asum << endl;
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
