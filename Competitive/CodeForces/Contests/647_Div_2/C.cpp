#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define M 1000001
void precalculate(vector<int>& an) {
	an[1] = 1;
	an[2] = 3;
	an[3] = 4;
	for (int i = 4;i <M;++i) {
		an[i] = an[(int)floor(i / 2)] + i;
	}
}
long long int func(long long int n,vector<int>& an) {
	if (n < M) {
		return an[n];
	}
	else {
		return func((long long int)floor(n / 2),an) + n;
	}
}
long long int solve(vector<int>& an) {
	long long int n;
	cin >> n;
	return func(n,an);
}
int main() {
	vector<int> an(M, 0);
	precalculate(an);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> t;
	while (t--) {
		cout << solve(an) << endl;
	}
	return 0;
}
