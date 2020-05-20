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
void input(vector<ll>& arr, ll n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
void solve() {
	ll n, power;
	cin >> n >> power;
	vector<ll> arr(n);
	input(arr, n);
	priority_queue<ll> pq;
	for (int i = 0;i < arr.size();++i) {
		pq.push(arr[i]);
	}
	int ans = 0;
	while (!pq.empty()&&power > 0) {
		ll tmp = pq.top();
		pq.pop();
		power = power - tmp;
		ans++;
		tmp = tmp / 2;
		if (tmp > 0) {
			pq.push(tmp);
		}
	}
	if (power > 0 && pq.empty()) {
		cout << "Evacuate" << endl;
		return;
	}
	cout << ans << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
