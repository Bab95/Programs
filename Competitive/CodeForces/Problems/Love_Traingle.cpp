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
using namespace std;
void debugGraph(vector<vector<int> >& graph) {
	for (int i = 0;i<graph.size();++i) {
		cout << i << " :";
		for (int j = 0;j<graph[i].size();++j) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}
void input(vector<ll>& arr, ll n) {
	fo(i, 0, n - 1) {
		cin >> arr[i];
	}
}
/*bool dfs(vector<vector<int> >& graph,vector<bool>& visited,vector<int>& parent,int i){
visited[i] = true;
for(int j=0;j<graph[i].size();++j){
if(!visited[graph[i][j]]){
parent[graph[i][j]] = i;
bool ans = dfs(graph,visited,i,graph[i][j]);
}else if(graph[i][j]!=parent[graph[i][j]]){
int parentparent = parent[parent[graph[i][j]]];
}
}
}*/
void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	input(arr, n);
	/*vector<vector<int> > graph(n+1,vector<int>());
	for(int i=1;i<=n;++i){
	graph[i].push_back(arr[i-1]);
	}
	vector<bool> visited(n+1,false);
	vector<bool> instak(n+1,false);
	for(int i=1;i<=n;++i){
	if(!visited[i]){
	dfs(graph,visited,instak,i,1);
	}
	}*/\
		for (int i = 1;i <= n;++i) {
			int l1 = i;    //1
			int l2 = arr[i - 1]; //2
			int l3 = arr[l2 - 1];
			int l4 = arr[l3 - 1];
			if (l4 == l1) {
				cout << "Yes" << endl;
				return;
			}
		}
	cout << "No" << endl;
}
int main() {
	speed;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
