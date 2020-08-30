#include <iostream>
using namespace std;
void build_graph(vector<vector<int> >& graph,vector<vector<int> >& edges){
  for(auto it : edges){
    graph[it[0]].push_back(it[1]);
    graph[it[1]].push_back(it[0]);
  }
}
int in[101],low[101];
bool visited[101];
void dfs(vector<vector<int> >& graph,int node,int parent){
  //need to pass parent to distinguish between parent and ancestor...
  visited[node] = true;
  in[node] = low[node] = timer;
  timer++;
  for(auto child : graph[node]){
    if(child==parent){
      continue;
    }
    if(visited[child]){ //it is back edge...[ancestor]
      //node - child edge is back edge
      low[node] = min(low[node],in[child]);
    }else{
      //forward edge.....
      dfs(graph,child,node);
      //now after recursion complete as this was a forward edge we need to check
      //if it is a bridge or not....
      //for that to happen low time of child should be greater than or equal to in time of node...
      //child's low time is less than node that means that child is actually connected to ancestor of
      //node....
      if(low[child]>in[current]){
        cout<<node<<" and "<<child<<"node is a bridge...."<<endl;
      }
      low[node] = min(low[node],low[child]);

    }
  }
}
int main(){
    int n;
    vector<vector<int> > edges;
    vector<vector<int> > graph(n,vector<int>());
    build_graph(graph,edges);
}
