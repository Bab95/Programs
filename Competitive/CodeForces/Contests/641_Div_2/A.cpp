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
#define M 1000000
using namespace std;
bool primes[M+1];
void findPrime() {
	memset(primes, true, sizeof(primes));
	for (int i = 2;i*i <= M;i++) {
		if (primes[i] == true) {
			for (int j = i*i;j <= M;j += i) {
				primes[j] = false;
			}
		}
	}
}
void solve() {
	ll n, k;
	cin >> n >> k;
	if (primes[n] == true) {
		n = n * 2 + (k - 1) * 2;
	}
	else {
		while (k>0&&n % 2 != 0) {
			k--;
			for (int i = 3;i*i <= n;i += 2) {
				if (n%i == 0) {
					n += i;
					break;
				}
			}
		}

		if (k > 0 && n % 2 == 0) {
			n = n + k * 2;
		}
	}
	cout << n << endl;
}

int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int t;
	cin >> t;
	findPrime();
	while (t--) {
		solve();
	}
	return 0;
}
