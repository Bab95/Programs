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
/*bool primes[M+1];
void findPrime() {
	memset(primes, true, sizeof(primes));
	for (int i = 2;i*i <= M;i++) {
		if (primes[i] == true) {
			for (int j = i*i;j <= M;j += i) {
				primes[j] = false;
			}
		}
	}
}*/
void solve() {
	ll n, m;
	cin>>n>>m;
	if(n==1){
		cout<<0<<endl;
		return;
	}else if(n==2){
		cout<<m<<endl;
		return;
	}else{
		cout<<m*2<<endl;
	}
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
