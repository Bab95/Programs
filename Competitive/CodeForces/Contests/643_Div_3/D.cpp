#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
#define M 1000000
using namespace std;
struct mycompare {
	bool operator()(const pair<int,int>& p1,const pair<int,int>& p2) {
		if (p1.first<p2.first) {
			return true;
		}else if (p1.first == p2.first) {
			if (p1.second > p2.second) {
				return true;
			}
		}
		return false;
	}
};
void solve() {
	ll n, k;
	cin >> n;
	vector<int> arr(n + 1, 0);
	priority_queue < pair<int, int>, vector<pair<int, int> >, mycompare >  pq;
	pair<int,int> p;
	p.first = n;
	p.second = 1;
	pq.push(p);
	int index = 1;
	while (!pq.empty() && index <= n) {
		p = pq.top();
		pq.pop();
		int r = p.second + p.first - 1;
		int l = p.second;
		int mid = (r + l)/2;
		arr[mid] = index++;
		if (mid - p.second) {
			pq.push(make_pair( mid - p.second,p.second));
		}
		if (r - mid) {
			pq.push(make_pair(r - mid,mid + 1));
		}

	}
	for (int i = 1;i <= n;++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
/*


*/
