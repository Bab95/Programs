#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
vector<vector<int> > graph;
int n,m;
int dist[1005];
void bfs(int src){
	for(int i=0;i<=n;i++){
		dist[i] = INT_MAX;
	}
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	vector<bool> visited(n+1,false);
	while(!q.empty()){
		int s = q.front();
		q.pop();
		visited[s] = true;
		for(vector<int>::iterator itr=graph[s].begin();itr!=graph[s].end();itr++){
			int d = *itr;
			if(!visited[d]&&dist[d]>dist[s]+6){
				dist[d] = dist[s]+6;
				q.push(d);
			}
		}
	}
}
int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> tmp;
		for(int i=0;i<=n;i++){
			graph.push_back(tmp);
		}
		int a,b;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int src;
		cin>>src;
		bfs(src);
		for(int i=1;i<=n;i++){
			if(i==src){
				continue;
			}

			if(dist[i]==INT_MAX){
				cout<<-1<<" ";
			}else
				cout<<dist[i]<<" ";
		}
		cout<<endl;
		graph.clear();
	}
}
