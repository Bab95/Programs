#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define INF 1e9+9
void input(vector<int>& arr, int n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	int x = n;
	vector<int> num;
	while (x) {
		int rem = x % 10;
		x = x / 10;
		num.push_back(rem);
	}
	int i = 0;
	for (int j = 0;j<num.size();++j) {
		if (num[j] != 0)
			ans.push_back((int)num[j] * (pow(10, j)));
	}
	cout << ans.size() << endl;
	for (int i = 0;i<ans.size();++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main() {
	int t;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
