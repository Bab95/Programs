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
int binary_Search_Smaller(vector<int>& v, int low, int high, int key,int &prev_ans) {
	if (low <= high) {
		int mid = low + (high-low) / 2;
		if (v[mid] == key) {
			return mid;
		}
		else if (v[mid] > key) {
			return binary_Search_Smaller(v, low, mid - 1, key, prev_ans);
		}
		else if (v[mid] < key) {
			prev_ans = mid;
			return binary_Search_Smaller(v, mid + 1, high, key, prev_ans);
		}
	}
	return prev_ans;
}
int binary_Search_Greater(vector<int>& w, int low, int high, int key,int &prev_ans) {
	if (low <= high) {
		int mid = low + (high - low) / 2;
		if (w[mid] == key) {
			return mid;
		}
		else if (w[mid] > key) {
			prev_ans = mid;
			return binary_Search_Greater(w, low, mid - 1, key, prev_ans);
		}
		else if (w[mid] < key) {
			return binary_Search_Greater(w, mid + 1, high, key, prev_ans);
		}
	}
	return prev_ans;
}
void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<pair<int, int> > arr(n);
	vector<int> v(x);
	vector<int> w(y);
	for (int i = 0;i < n;++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0;i < x;++i) {
		cin >> v[i];
	}
	for (int i = 0;i < y;++i) {
		cin >> w[i];
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	int ans = INT_MAX;
	for (int i = 0;i < n;++i) {
		//for pair 1......
		//search in v for wormhole just lower or equal.....
		//and in w search for just greater than or equal.....
		//if t1 ||t2 comes out to be -1 then its totally not possible to pic that examination as we don't have enough time.....
		int prev_t1=-1, prev_t2=-1;
		int t1 = binary_Search_Smaller(v, 0, v.size() - 1, arr[i].first,prev_t1);
		int t2 = binary_Search_Greater(w, 0, w.size() - 1, arr[i].second,prev_t2);
		if (t1 == -1 || t2 == -1) {
			continue;
		}
		int time = w[t2] - v[t1] + 1;
		if (time < ans) {
			ans = time;
		}
	}
	cout << ans << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
