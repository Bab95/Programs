
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
void input(vector<pair<ll, int> >& arr, ll n) {
	fo(i, 0, n - 1) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
}
void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n+1);
	for (int i = 1;i <= n;++i) {
		cin >> arr[i];
	}
	sort(arr.begin() + 1, arr.end());
	int current = 1;
	for (int i = n;i >= 1;i--) {
		if (arr[i] < i + 1) {
			current = i + 1;
			break;
		}
	}
	cout << current << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
