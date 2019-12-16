#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 100
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int t;
	string s;
	freopen("input.txt", "r", stdin);
	cin >> t;
	int dp[MAX_SIZE][MAX_SIZE];
	while (t--) {
		cin >> s;
		int n = s.length();
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 0;i < n;i++) {
			dp[i][i] = 1;
		}
		int k;
		for (k = 2;k <= n;k++) {
			for (int i = 0;i < n - k + 1;i++) {
				int j = i + k - 1;
				if (s[i] == s[j] && k == 2) {
					dp[i][j] = 2;
				}
				else if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	system("pause");
	return 0;
}
