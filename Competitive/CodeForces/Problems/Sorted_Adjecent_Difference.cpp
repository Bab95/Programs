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
void generatePrimes() {

}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void input(vector<int>& arr, int n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
void input(vector<ll>& arr, int n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
void input(vector<ulli>& arr, int n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
ll max(ll a, ll b) {
	return a>b ? a : b;
}
ulli max(ulli a, ulli b) {
	return a>b ? a : b;
}
int max(int a, int b) {
	return a>b ? a : b;
}
void print(vector<int>& ans, int n) {
	fo(i, 0, n - 1) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
void print(vector<ll>& ans, int n) {
	fo(i, 0, n - 1) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
struct node {
	int x, y;
};
void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	input(arr, n);
	sort(arr.begin(), arr.end());
	vector<ll> ans;
	ans.reserve(n);
	int mid = (n-1) / 2;
	int r = 1;
	int l = 1;
	int size = 0;
	ans.pb(arr[mid]);
	size = 1;
	while (size<n) {
		if (mid + r < n) {
			ans.push_back(arr[mid + r]);
			r++;
			size++;
		}
		if (mid - l >= 0) {
			ans.push_back(arr[mid - l]);
			++l;
			++size;
		}
	}
	print(ans, n);
	cout << endl;
}
int main() {
	speed;
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
