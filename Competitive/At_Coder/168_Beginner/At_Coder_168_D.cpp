#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define pb push_back
#define po pop_back
#define INF 1e9+9
pair<long long int, long long int> dfs(vector<vector<long long int> >& graph, long long int start, vector<long long int>& visited, vector<pair<long long int, long long int> >& dp) {
	visited[start] = true;
	pair<long long int, long long int> ans;
	ans.first = INT_MAX;
	ans.second = INT_MAX;
	for (long long int i = 0;i<graph[start].size();++i) {
		if (graph[start][i] == 1) {
			return make_pair(1, 1);
		}
		if (!visited[graph[start][i]]) {
			//min_dist = min(dfs(graph,graph[start][i],visited,next,dp));
			pair<long long int, long long int> p = dfs(graph, graph[start][i], visited, dp);
			if (p.first<ans.first) {
				ans.first = p.first;
				ans.second = graph[start][i];
			}
		}
		else {
			if (dp[graph[start][i]].first + 1<ans.first) {
				ans.first = dp[graph[start][i]].first + 1;
				ans.second = graph[start][i];
			}
		}
	}
	dp[start].first = ans.first;
	dp[start].second = ans.second;
	return ans;
}
void bfs(vector<vector<long long int> >& graph,int i,vector<int>& next) {
	vector<bool> visited(graph.size() + 1, false);
	vector<long long int> dist(graph.size() + 1, INT_MAX);

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	visited[1] = true;
	while (!q.empty()) {
		int root = q.front();
		q.pop();
		//int n = q.size();
		for (int i = 0;i < graph[root].size();++i) {
			if (!visited[graph[root][i]]) {
				dist[graph[root][i]] = dist[root] + 1;
				visited[graph[root][i]] = true;
				q.push(graph[root][i]);
				next[graph[root][i]] = root;
			}
		}
	}

	for (int i = 2;i < next.size();++i) {
		if (next[i] == -1) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	for (int i = 2;i < next.size();++i) {
		cout << next[i] << endl;
	}
}
void solve() {
	long long int n, m, a, b;
	//vector<vector<long long int> > graph(n+1,vector<long long int>());
	cin >> n >> m;
	vector<vector<long long int> > graph(n + 1, vector<long long int>());
	for (long long int i = 0;i<m;++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> next(n + 1, -1);
	bfs(graph, 1, next);
	/*vector<long long int> visited(n + 1, false);
	vector<pair<long long int, long long int> > dp(n + 1, make_pair(INT_MAX, -1));
	for (long long int i = 2;i <= n;++i) {
		if (!visited[i]) {
			dfs(graph, i, visited, dp);
		}
	}
	for (long long int i = 2;i <= n;++i) {
		cout << dp[i].second << " ";
	}*/
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
