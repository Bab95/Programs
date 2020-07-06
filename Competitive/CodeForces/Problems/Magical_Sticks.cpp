#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
void input_vector(vector<int>& v) {
	for (int i = 0;i<v.size();++i) {
		cin >> v[i];
	}
}
void solve() {
	int n, k, m;
	cin >> n;
	cout << max((n + 1) / 2, 1) << endl;
}
int main() {
	int t;
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
