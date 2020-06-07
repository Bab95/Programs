#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void resetMAp(unordered_map<int, int>& mmap) {
	for (auto it = mmap.begin();it != mmap.end();++it) {
		it->second = 1;
	}
}
int solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	unordered_map<int, int> mmap;
	for (int i = 0;i<n;++i) {
		cin >> arr[i];
		mmap[arr[i]] += 1;
	}
	for (int k = 1;k<1024;++k) {
		for (int i = 0;i<n;++i) {
			int z = arr[i] ^ k;
			if (mmap.find(z) == mmap.end()) {
				resetMAp(mmap);
				continue;
			}
			else if (mmap[z] < 1) {
				resetMAp(mmap);
				continue;
			}
			else {
				mmap[z]--;
			}
		}
		bool yes = true;
		for (auto it = mmap.begin();it != mmap.end();++it) {
			if (it->second != 0) {
				// this is not the answer move on...
				yes = false;
				resetMAp(mmap);
				break;
			}
			else {
				continue;
			}
		}
		if (yes) {
			return k;
		}

	}
	return -1;
}
int main() {
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}
