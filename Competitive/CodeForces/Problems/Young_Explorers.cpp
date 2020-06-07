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
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n;++i) {
		cin >> arr[i];
	}
	map<int, int> mmap;
	for (int i = 0;i < n;++i) {
		mmap[arr[i]] += 1;
	}
	int left = 0;
	int ans = 0;
	for (auto it = mmap.begin();it != mmap.end();++it) {
		it->second += left;
		ans += (it->second / it->first);
		left = (it->second%it->first);
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
