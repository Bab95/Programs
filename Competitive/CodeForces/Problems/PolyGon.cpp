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
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);std::cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void debugGraph(vector<vector<int> >& graph) {
	for (int i = 0;i<graph.size();++i) {
		std::cout << i << " :";
		for (int j = 0;j<graph[i].size();++j) {
			std::cout << graph[i][j] << " ";
		}
		std::cout << endl;
	}
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(ll *a, ll *b) {
	ll tmp = *a;
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
		std::cout << ans[i] << " ";
	}
	std::cout << endl;
}
void print(vector<ll>& ans, int n) {
	fo(i, 0, n - 1) {
		std::cout << ans[i] << " ";
	}
	std::cout << endl;
}
void solve() {
	ll n;
	cin >> n;
	vector<string> mat;
	mat.reserve(n);
	string tmp;
	for (int i = 0;i < n;++i) {
		cin >> tmp;
		mat.push_back(tmp);
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (mat[i][j] == '1') {
				if (i == n - 1 || j == n - 1) {
					continue;
				}
				else {
					bool f1 = false;
					bool f2 = false;
					if (i + 1 < n&&mat[i+1][j]=='1') {
						f1 = true;
					}
					if (j + 1 < n&&mat[i][j + 1] == '1') {
						f2 = true;
					}
					if (f1 == false && f2 == false) {
						std::cout << "NO" << endl;
						return;
					}
				}
			}
		}
	}
	std::cout << "YES" << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
