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
void solve() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<bool> arr(101, false);
	//input(arr,n);
	vector<int> array(n);
	fo(i, 0, n - 1) {
		cin >> array[i];
		arr[array[i]] = true;
	}
	int m;
	cin >> m;
	vector<int> brr(m);
	input(brr, m);
	sort(array.begin(), array.end());
	sort(brr.begin(), brr.end());
	vector<vector<int> > graph(101, vector<int>());
	for (int i = 1;i<101;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	fo(i, 0, m - 1) {
		int x = brr[i];
		cout << x - 1 << " " << x << " " << x + 1 << endl;
		if (arr[x - 1] == true) {
			graph[x - 1].push_back(i);
		}
		if (arr[x + 1] == true) {
			graph[x + 1].push_back(i);
		}
		if (arr[x] == true) {
			graph[x].push_back(i);
		}
	}
	fo(i, 0, n - 1) {
		cout << array[i] << " :";
		print(graph[array[i]], graph[array[i]].size());
	}
	vector<bool> paired(m, false);
	int count = 0;
	fo(i, 0, n - 1) {
		for (int j = 0;j<graph[array[i]].size();++j) {
			if (!paired[graph[array[i]][j]]) {
				count++;
				paired[graph[array[i]][j]] = true;
			}
		}
	}
	cout << count << endl;
}
int main() {
	speed;
	solve();
	return 0;
}
