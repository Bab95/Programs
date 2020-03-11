#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > graph;
int dfs(vector<bool> &visited,int &res,int u){
	visited[u] = true;
	int cnodes=0,subnodes=0;
	vector<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		if(!visited[*itr]){
			subnodes = dfs(visited,res,*itr);
			if(subnodes%2==0){
				res++;
			}else{
				cnodes+=subnodes;
			}
		}
	}
	return cnodes+1;
}
int findEdges(int n){
	vector<bool> visited(n+1,false);
	int res = 0;
	dfs(visited,res,1);
	return res;
}
int main(int argc, char *argv[]) {
	int n,e;
	cin>>n>>e;
	vector<int> tmp;
	for(int i=0;i<=n;i++){
		graph.push_back(tmp);
	}
	int a,b;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int sol = findEdges(n);
	cout<<sol<<endl;
}
