#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int drops(int position[], int speed[], int length, int n) {
	vector<pair<int, double> > v(n);
	for (int i = 0;i < n;i++) {
		v[i].first = position[i];
		int tmp = length - position[i];
		v[i].second = 1.0*tmp / speed[i];
	}
	sort(v.begin(), v.end());
	stack<double> s;
	int drop = 0;
	for (int i = n - 1;i >= 0;i--) {
		if (s.empty()) {
			s.push(v[i].second);
		}
		if (v[i].second > s.top()) {
			s.pop();
			drop++;
			s.push(v[i].second);
		}
	}
	while (!s.empty()) {
		drop++;
		s.pop();
	}
	return drop;
}
int main() {
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	int n,length;
	while (t--) {
		cin >>length>> n;
		int *position = new int[n];
		int *speed = new int[n];
		for (int i = 0;i < n;i++) {
			cin >> position[i];
		}
		for (int i = 0;i < n;i++) {
			cin >> speed[i];
		}
		cout << drops(position, speed, length, n);
	}
	return 0;
}
