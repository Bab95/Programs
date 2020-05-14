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
struct mycompare{
	bool ()operator(pair<int,pair<int,int> >& p1,pair<int,pair<int,int> >& p2){
		if(p.first<p2.second){
			return true;
		}
		if(p1.first==p2.second){
			if(p1.second.first>p2.second.first){
				return true;
			}
		}
		return false;
	}
};
void solve() {
	ll n, k;
	cin>>n;
	vector<int> arr(n+1,0);
	priority_queue<pair<int,pair<int,int>,vector<pair<int,pair<int,int> > >,mycompare > pq;
 	pair<int,pair<int,int> > p;
	p.first = n;
	p.second.first = 1;
	p.second.second = n;
	pq.push(p);
	int index = 1;
	while(!pq.empty()&&index<=n){
		p = pq.top();
		pq.pop();
		if((p.second.second-p.second.first+1)%2!=0){
			arr[(p.second.second+p.second.first)/2] = index++;
			pair<int,pair<int,int> > q;
			q.second.first = p.second.first;
			q.second.second = (p.second.second+p.second.first)/2-1;
			q.first = q.second.second-q.second.first+1;
			if(q.second.second!=q.second.first){
				pq.push(q);
			}else{
				arr[(p.second.second+p.second.first-1)/2] = index++;
				pair<int,pair<int,int> > q;
				q.second.first = (p.second.second+p.second.first-1)/2+1;
				q.second.second = p.second.second;
				q.first = q.second.second-q.second.first+1;
				if(q.second.second!=q.second.first){
					pq.push(q);
			}
		}
	}
}
for(int i=1;i<=n;++i){
	cout<<arr[i]<<" ";
}
cout<<endl;
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
1
2 0
2 1 0
2 4 0 3
2 4 1 0 3
2 4 6 0 5 3


*/
