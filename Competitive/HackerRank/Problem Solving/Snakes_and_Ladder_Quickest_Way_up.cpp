#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define V 101
const int INF = 2000000000;
using namespace std;

int main(int argc, char *argv[]) {
	int t,l,s,m,n;
	cin>>t;

	while(t--){
		vector<vector<pair<int,int> > > graph(V);
		char board[101];
		memset(board,'a',sizeof(board));
		cin>>l;
		for(int i=0;i<l;i++){
			cin>>m>>n;
			graph[m].push_back(make_pair(0,n));
			board[m] = 'l';
		}
		cin>>s;
		for(int i=0;i<s;i++){
			cin>>m>>n;
			graph[m].push_back(make_pair(0,n));
			board[m] = 's';
		}
		for(int i=1;i<V;i++){
			for(int j=1;j<=6;j++){
				if(i+j>=V)
					break;
				else{
					if(board[i]=='a'){
						graph[i].push_back(make_pair(1,i+j));
					}
				}
			}
		}
		/*
		vector<vector<pair<int,int> > >::iterator itr;
		int v;
		for(itr=graph.begin(),v=0;itr!=graph.end();itr++,v++){
			vector<pair<int,int> >::iterator it;
			//it = *itr;
			cout<<v<<"->";
			for(it=itr->begin();it!=itr->end();it++){
				cout<<it->second<<" "<<it->first<<", ";
			}
			cout<<endl;
		}
		*/

		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		vector<int> dist(V,INF);
		vector<int> edgeto(V,-1);
		pq.push(make_pair(0,1));
		dist[1] = 0;
		bool flag100 = false;
		while(!pq.empty()){
			if(pq.top().second==100)
			{
				flag100 = true;
				break;
			}
			pair<int,int> p = pq.top();
			pq.pop();
			int src = p.second;
			vector<pair<int,int> >::iterator it;
			for(it=graph[src].begin();it!=graph[src].end();it++){
				int dest = it->second;
				int weight = it->first;
				if(dist[src]+weight<dist[dest]){
					dist[dest] = dist[src]+weight;
					edgeto[dest] = src;
					pq.push(make_pair(dist[dest],dest));
				}

			}


		}
		if(flag100){
			//cout<<"ohhh yeah"<<endl;
			cout<<dist[100]<<endl;
		}else{
			cout<<-1<<endl;
		}

		//graph.clear();
	}

}
