/*30_Points*/
#include <bits/stdc++.h>
#define M 200001
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
bitset<M> visited;
/*
void dfs(vector<unordered_set<int> >& graph,int node,vector<int>& F,vector<int>& A,vector<int>& ans,int& day,int& Api,unordered_set<int>& visited){
	visited.insert(node);
	if(F[node]!=0){
        F[node] -= min(Api,F[node]);
        if(F[node]==0){
            ans[node] = day + 1;
        }
	}
    for(auto it=graph[node].begin();it!=graph[node].end();++it){
        int child = *it;
		if(visited.find(child)==visited.end()){
        	dfs(graph,child,F,A,ans,day,Api,visited);
		}
    }
}
*/
void bfs(vector<unordered_set<int>>& graph,int node,vector<int>& F,vector<int>& A,vector<int>& ans,int& day,int& Api,int n){
    queue<int> q;
    q.push(node);
    visited.reset();
    while(!q.empty()){
        int current = q.front();
        visited.set(current);
        if(F[current]!=0){
            F[current] -= min(F[current],Api);
            if(F[current]==0){
                ans[current] = day + 1;
            }
        }
        q.pop();
        for(auto it=graph[current].begin();it!=graph[current].end();++it){
            int child = *it;
            if(!visited[child]){
                q.push(child);
            }
        }

    }
}
void solve(){
	int n;
	int a,b;
	cin>>n;
	vector<int> P(n+1),A(n+1),F(n+1),ans(n+1,-1);
	vector<unordered_set<int> > graph(n+1,unordered_set<int>());
	for(int i=0;i<n-1;++i){
		cin>>a>>b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	for(int i=0;i<n;++i){
		cin>>P[i];
	}
	for(int i=1;i<=n;++i){
		cin>>A[i];
	}
	for(int i=1;i<=n;++i){
		cin>>F[i];
	}
    int city = P[0];
    int Api = A[city];
    for(int i=1;i<=n;++i){
        F[i] -= min(Api,F[i]);
        if(F[i]==0){
            ans[i] = 1;
        }
    }
    for(auto child : graph[city]){
        graph[child].erase(city);
    }
    graph[city].clear();
	for(int day=1;day<n;++day){
		int city = P[day];
		int Api = A[city];
		bfs(graph,city,F,A,ans,day,Api,n);
        for(auto child : graph[city]){
            graph[child].erase(city);
        }
		graph[city].clear();
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int t;
	speed;
	cin>>t;
	while(t--){
		solve();
	}
}
