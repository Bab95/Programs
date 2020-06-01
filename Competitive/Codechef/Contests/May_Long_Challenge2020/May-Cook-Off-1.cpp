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
#include <string.h>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void input(vector<pair<ll,int> >& arr, ll n) {
	fo(i, 0, n - 1) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
}
void solve() {
	ll n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n;++i) {
		cin >> arr[i];
	}
	unordered_map<int, int> mmap;
	int i = 0;
	while (i < n) {
		int current = arr[i];
		if (mmap.find(current) != mmap.end()) {
			cout << "NO" << endl;
			return;
		}
		while (i < n&&arr[i] == current) {
			mmap[arr[i]] += 1;
			++i;
		}
	}
	unordered_map<int, int> quantity;
	for (auto it = mmap.begin();it != mmap.end();++it) {
		quantity[it->second]++;
	}
	if (quantity.size() != mmap.size()) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;

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

/*
1 2 3 4 5
2 3 4 5
3 4 5
4 5
*/
