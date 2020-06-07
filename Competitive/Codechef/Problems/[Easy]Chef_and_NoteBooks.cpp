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
#include <string>
#include <math.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve() {
	int x, y, k, n;
	cin >> x >> y >> k >> n;
	vector<pair<int, int> > prices(n);
	for (int i = 0;i < n;++i) {
		cin >> prices[i].first >> prices[i].second;
	}
	for (int i = 0;i < n;++i) {
		if (prices[i].first >= (x - y) && prices[i].second <= k) {
			cout << "LuckyChef" << endl;
			return;
		}
	}
	cout << "UnluckyChef" << endl;
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
