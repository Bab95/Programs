#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1;i <= n;++i) {
		cin >> arr[i];
	}
	vector<vector<int> > res;
	vector<bool> visited(n + 1, false);
	for (int i = 1;i <= n;++i) {
		if (!visited[i]) {
			vector<int> tmp;
			tmp.push_back(i);
			int next = arr[i];
			while (next != i) {
				tmp.push_back(next);
				visited[next] = true;
				next = arr[next];
			}
			tmp.push_back(next);
			res.push_back(tmp);
		}
	}
	cout << res.size() << endl;
	for (int i = 0;i < res.size();++i) {
		for (int j = 0;j < res[i].size();++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
