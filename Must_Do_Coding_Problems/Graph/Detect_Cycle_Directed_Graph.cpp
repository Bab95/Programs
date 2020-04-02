#include <bits/stdc++.h>
using namespace std;
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCycle(vector<int> adj[],vector<bool>& visited,vector<bool>& recuring,int x){
    visited[x] = true;
    recuring[x] = true;
    for(int i=0;i<adj[x].size();i++){
        if(!visited[adj[x][i]]&&isCycle(adj,visited,recuring,adj[x][i])){
            return true;
        }else if(recuring[adj[x][i]]){
            return true;
        }
    }
    recuring[x] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> visited(V,false);
    vector<bool> recuring(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            bool cycle = isCycle(adj,visited,recuring,i);
            if(cycle){
                //cout<<"for i:"<<i<<endl;
                return true;
            }
        }
    }
    return false;
}
int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}



/*
4
2 2
0 1 0 0
4 3
0 1 1 2 2 3
29 4
6 21 17 12 2 11 9 11
4 3
0 1 2 3 3 2
*/
