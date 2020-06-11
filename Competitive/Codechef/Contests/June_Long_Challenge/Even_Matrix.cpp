#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
#define speed ios::sync_with_stdio(0);cin.tie(0)
typedef long long int ll;
void print(vector<vector<int> >& arr, int n) {
	for (int i = 0;i<n;++i) {
		for (int j = 0;j<n;++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void fill(vector<int>& a, int i) {
	for (int j = 0;j < a.size();++j) {
		a[j] = i + j;
	}
}
void solve() {
	int n;
	cin >> n;
	vector<vector<int> > arr(n, vector<int>(n));
	if (n % 2 == 1) {
		int i = 1;
		for (int j = 0;j < n;++j) {
			fill(arr[j], i);
			i = i + n;
		}
	}
	else {
		int i = 1;
		for(int j=0;j<n;++j)
			if (j % 2 == 0) {
				fill(arr[j], i);
				i = i + n;
			}
			else {
				fill(arr[j], i);
				i = i + n;
				for (int p = 0;p < n;p += 2) {
					swap(arr[j][p], arr[j][p + 1]);
				}
			}

		}
		print(arr, n);
}
int main() {
	speed;
	//freopen("input.txt", "r", stdin);
	int r;
	cin >> r;
	int t = 1;
	while (t<=r) {
		//cout << "#" << t << "test:" << endl;
		solve();
		++t;
	}
	return 0;
}
