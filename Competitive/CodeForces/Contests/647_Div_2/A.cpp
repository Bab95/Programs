#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int solve() {
	long long int a, b;
	cin >> a >> b;
	if (a == b) {
		return 0;
	}
	int p2 = 0;
	if (b<a) {
		long long int t = a;
		a = b;
		b = t;
	}
	if (b%a != 0) {
		return -1;
	}
	else {
		int ans = 0;
		long long int tmp = b / a;
		while (tmp % 8 == 0) {
			ans++;
			tmp = tmp / 8;
		}
		if (tmp == 1) {
			return ans;
		}
		while (tmp % 4 == 0) {
			tmp = tmp / 4;
			ans++;
		}
		if (tmp == 1) {
			return ans;
		}
		while (tmp % 2 == 0) {
			tmp = tmp / 2;
			ans++;
		}
		if (tmp == 1) {
			return ans;
		}
	}
	return -1;
}
int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}
