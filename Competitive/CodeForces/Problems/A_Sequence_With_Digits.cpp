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
	unsigned long long int a, k;
	unsigned long long int ans;
	cin >> a >> k;
	int m, n;
	ans = a;
	for (unsigned long long int i = 1;i < k;++i) {
		ans = a;
		m = 9;
		n = 0;
		while (a) {
			m = min(m, (int)(a % 10));
			n = max(n, (int)(a % 10));
			a = a / 10;
		}
		ans += m*n;
		a = ans;
		if (m == 0 || n == 0) {
			break;
		}
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
