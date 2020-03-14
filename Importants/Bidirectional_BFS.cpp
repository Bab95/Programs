#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class Graph{
  int V,
  list<int> *adj;
  pubic:
    Graph(int V);
    void addEdge(int u,int v);
    void BFS(list<int> *queue,bool *visited,int *parent);
    int bidirectionalsearch(itn s,int t);
    int isIntersecting(bool *s_visited,bool *t_visited);
    void printPath(int *s_parent,int *t_parent,int s,int t,int intersection_node);
}
Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
};
void Graph::addEdge(int u,int v){
  this->adj[u].push_back(v);
  this->adj[v].push_back(u);
};
void Graph::BFS(list<int> *queue,bool *visited,int *parent){
  int current = queue->front();
  queue->pop();
  list<int>::iterator itr;
  for(itr=adj[current].begin();itr!=adj[current].end();itr++){
    if(!visited[*itr]){
      parent[*itr] = current;
      visited[*itr] = true;
      queue.push_back(*itr);
    }
  }
};
int Graph::isIntersecting(bool *s_visited,bool *t_visited){
  int intersection_node = -1;
  for(int i=0;i<V;i++){
    if(s_visited[i]&&t_visited[i]){
      return i;
    }
  }
  return intersection_node;
};
void Graph::printPath(int *s_parent,int *t_parent,int s,int t,int intersection_node){
  vector<int> path;
  path.push_back(intersection_node);
  int i = intersection_node;
  while(i!=s){
    path.push_back(s_parent[i]);
    i = s_parent[i];
  }
  reverse(path.begin(),path.end());
  i = intersection_node;
  while(i!=t){
    path.push_back(t_parent[i]);
    i = t_parent[i];
  }
  vector<int>::iterator itr;
  for(itr=path.begin();itr!=path.end();itr++){
    cout<<*itr<<" ";
  }
  cout<<endl;
};
int Graph::bidirectionalsearch(int s,int t){
  bool s_visited[V],t_visited[V];
  int s_parent[V],t_parent[V];
  list<int> s_queue,t_queue;
  int intersection_node = -1;
  for(int i=0;i<V;i++){
    s_visited[i] = false;
    t_visited[i] = false;
  }
  s_queue.push_back(s);
  s_visited[s] = true;
  s_parent[s] = -1;

  s_queue.push_back(t);
  t_visited[t] = true;
  t_parent[t] = -1;

  while(!s_queue.empty() && !t_queue.empty()){
    BFS(&s_queue,s_visited,s_parent);
    BFS(&t_queue,t_visited,t_parent);
    intersection_node = isIntersecting(s_visited,t_visited);
    if(intersection_node!=-1){
      cout<<"path exists"<<endl;
      printPath(s_parent,t_parent,s,t,intersection_node);
      return 1;
    }
  }
  return -1;
};
