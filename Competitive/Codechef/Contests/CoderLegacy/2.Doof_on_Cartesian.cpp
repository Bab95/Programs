#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
typedef long long int ulli;
#define int_64 int64_t
using namespace std;
int check(pair<int, int>& A, pair<int, int>& B, pair<int, int>& C) {
    pair<int_64,int_64> a,b,c;
    a.first = (int_64)A.first;
    a.second = (int_64)A.second;
    b.first = B.first;
    b.second = B.second;
    c.first = C.first;
    c.second = C.second;
    int_64 ans;
	ans = a.first*(b.second - c.second) - a.second*(b.first - c.first) + (b.first*c.second - b.second*c.first);
	if(ans>0){
	    return 1;
	}else if(ans<0){
	    return -1;
	}
	return (int)ans;
}
void binary_Search(vector<int>& lines, int low, int high, pair<int, int>& point, int& ans) {
	if (low>high) {
		return;
	}
	int mid = (low + high) / 2;
	int a = lines[mid];
	pair<int, int> A = make_pair(a, 0);
	pair<int, int> B = make_pair(0, a);
	int current = check(A, B, point);
	if (current == 0) {
		ans = -1;
		return;
	}
	else if (current>0) {
		ans = mid;
		binary_Search(lines, low, mid - 1, point, ans);
	}
	else if (current<0) {
		ans = mid+1;
		binary_Search(lines, mid + 1, high, point, ans);
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int> lines(n);
	for (int i = 0;i<n;++i) {
		cin >> lines[i];
	}
	int q;
	cin >> q;
	vector<pair<int, int> > points(q);
	for (int i = 0;i<q;++i) {
		cin >> points[i].first >> points[i].second;
	}
	pair<int, int> A = make_pair(lines[0], 0);
	pair<int, int> B = make_pair(0, lines[0]);
	pair<int, int> C = make_pair(lines[n-1],0);
	pair<int, int> D = make_pair(0,lines[n-1]);
	for (int i = 0;i<q;++i) {
		int ans = -1;
		int current = check(A, B, points[i]);
		if (current > 0) {
			cout << 0 << endl;
			continue;
		}
		current = check(C,D,points[i]);
		if(current<0){
		    cout<<n<<endl;
		    continue;
		}
		binary_Search(lines, 0, n - 1, points[i], ans);
		cout << ans << endl;
	}
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
