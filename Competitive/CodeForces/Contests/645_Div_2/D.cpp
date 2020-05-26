
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
#define Mod 1000000007
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(2 * n);
	for (int i = 0;i < n;++i) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	vector<ll> prefix_hugs(2 * n + 1);
	vector<ll> prefix_days(2 * n + 1);
	prefix_hugs[0] = 0;
	prefix_days[0] = 0;
	for (int i=1;i <=2*n;++i) {
		prefix_hugs[i] = prefix_hugs[i - 1] + (arr[i - 1] * (arr[i - 1] + 1)) / 2;
		prefix_days[i] = prefix_days[i - 1] + arr[i-1];
	}
	ll max_ans = INT_MIN;
	for (ll i = 2 * n;i >= n+1;--i) {
		ll low = 1;
		ll high = i;
		ll ans = i;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (prefix_days[i] - prefix_days[mid] < x) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		ll rem = prefix_days[i] - prefix_days[ans - 1] - x;
		ll sum = prefix_hugs[i] - prefix_hugs[ans - 1];
		sum -= (rem*(rem + 1)) / 2;
		max_ans = max(max_ans, sum);
	}
	cout << max_ans << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
