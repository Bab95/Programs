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
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void solve() {
	string s;
	cin >> s;
	vector<int> hash(3, 0);
	int count = 0;
	int ans = INT_MAX;
	int start = 0;
	for (int i = 0;i<s.length();++i) {
		hash[s[i] - '1']++;
		if (hash[s[i] - '1'] == 1) {
			count++;
		}
		if (count == 3) {
			while (hash[s[start]-'1']>1) {
				hash[s[start]-'1']--;
				start++;
			}
			int window = i - start + 1;
			if (window<ans) {
				ans = window;
			}
		}

	}
	if (ans == INT_MAX) {
		cout << 0 << endl;
		return;
	}
	cout << ans << endl;

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
	return 0;
}
