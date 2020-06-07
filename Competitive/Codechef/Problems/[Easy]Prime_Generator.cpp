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
#define R 1000000001
vector<long long int> sieve() {
	long long int r = (long long int)sqrt(R);
	vector<bool> primes(r + 1, true);
	for (long long int i = 2;i*i <= r;++i) {
		if (primes[i]) {
			for (long long int j = i*i;j <= r;j += i) {
				primes[j] = false;
			}
		}
	}
	vector<long long int> ans;
	for (long long int i = 2;i <= r;++i) {
		if (primes[i]) {
			ans.emplace_back(i);
		}
	}
	return ans;
}
bool isprime(long long int l,vector<long long int>& primes) {
	if (l < 2) {
		return false;
	}
	if (l >= 2 && l < 4) {
		return true;
	}
	for (ll i = 0;i<primes.size()&&primes[i] * primes[i] <= l;++i) {
		if (l%primes[i] == 0) {
			return false;
		}
	}
	return true;
}
void solve(vector<long long int>& primes) {

	long long int l, r;
	cin >> l >> r;
	for (long long int i = l;i <= r;++i) {
		if (isprime(i,primes)) {
			cout << i << endl;
		}
	}
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	vector<long long int> primes = sieve();
	/*for (int i = 0;i < primes.size();++i) {
		cout << primes[i] << " ";
	}*/
	//cout << endl;
	int t;
	cin >> t;
	while (t--) {
		solve(primes);
		cout << endl;
	}
	return 0;
}
