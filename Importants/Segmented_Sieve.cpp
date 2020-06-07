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
#define R 1000000007
vector<int> sieve() {
	int r = (int)sqrt(R);
	vector<bool> primes(r + 1, true);
	for (int i = 2;i*i <= r;++i) {
		if (primes[i]) {
			for (int j = i*i;j <= r;j += i) {
				primes[j] = false;
			}
		}
	}
	vector<int> ans;
	for (int i = 2;i <= r;++i) {
		if (primes[i]) {
			ans.emplace_back(i);
		}
	}
	return ans;
}
void segmented_sieve(vector<int>& primes, long long int l, long long int r) {
	if (l < 2) {
		l = 2;
	}
	if (r < 2) {
		return;
	}
	vector<bool> prims(r - l + 1, true);
	for (long long int i = 0;i<primes.size()&&((long long int)primes[i] * (long long int)primes[i] <= r);++i) {
		long long int currentPrime = (long long int)primes[i];
		long long int base = (l / currentPrime)*(currentPrime);
		if (base < l) {
			base = base + currentPrime;
		}
		for (long long int j = base;j <= r;j += currentPrime) {
			prims[j - l] = false;
		}
		if (base == currentPrime) {
			prims[base - l] = true;
		}
	}
	for (long long int i = 0;i <= r-l;++i) {
		if (prims[i]) {
			cout << i + l << endl;
		}
	}
	return;
}
void solve(vector<int>& primes) {

	long long int l, r;
	cin >> l >> r;
	segmented_sieve(primes, l, r);
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	vector<int> primes = sieve();
	for (int i = 0;i < primes.size();++i) {
		cout << primes[i] << " ";
	}
	cout << endl;
	int t;
	cin >> t;
	while (t--) {
		solve(primes);
		cout << endl;
	}
	return 0;
}
