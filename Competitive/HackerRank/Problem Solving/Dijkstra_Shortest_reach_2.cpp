#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int M = 100001;
const int INF = 20000000;
int main(int argc, char *argv[]) {
	int t,V,E;
	cin>>t;
	while(t--){
		cin>>V>>E;
		int graph[V][V];
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				graph[i][j] = M;
			}
		}
		//memset(graph,M,sizeof(graph));
		int p,q,r;
		for(int i=0;i<E;i++){
			cin>>p>>q>>r;
			if(r<graph[p-1][q-1]){
				graph[p-1][q-1] = r;
				graph[q-1][p-1] = r;
			}
		}
		//cout<<"Enter s:";
		int s;
		cin>>s;
		/*for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
		vector<int> dist(V,INF);
		dist[s-1] = 0;
		vector<bool> visited(V,false);
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		pq.push(make_pair(0,s-1));
		while(!pq.empty()){
			int src = pq.top().second;
			visited[src] = true;
			pq.pop();
			for(int i=0;i<V;i++){
				if(!visited[i]&&(graph[src][i]!=M)&&(dist[src]+graph[src][i]<dist[i])){
					dist[i] = dist[src]+graph[src][i];
					pq.push(make_pair(dist[i],i));
				}
			}
		}

		for(int i=0;i<V;i++){
			if(i==s-1)
				continue;
			if(dist[i]==INF){
				cout<<-1<<" ";
				continue;
			}
			cout<<dist[i]<<" ";
		}
		cout<<endl;



	}
}
