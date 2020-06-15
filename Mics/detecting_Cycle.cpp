//Notes on disjoint subsets and union and find operations.
//This is used in krushkal's algorithm..
//Also used in cycle detection...


//return subset to which node belongs
int find(vector<int>& parent,int i){
  if(parent[i]==-1){
    //self set...
    return i;
  }
  return find(parent,parent[i]);
  //(1)<--(2)<---(3)
  //3's parent is 2 and 2's parent is 1
}
void union(vector<int>& parent,int x,int y){
  int xset = find(parent,x);
  int yset = find(parent,y);
  if(xset!=yset){
    parent[xset] = yset;
  }
}
bool cycle(Graph g){
  vector<int> parent(n,-1);
  for(int i=0;i<g.size();++i){
    int x = find(parent,g[i].first);
    int y = find(parent,g[i].second);
    if(x==y){
      //x and y belong to same subset.....
      return true;
    }
    union(parent,x,y);
  }
  return false;
}

//optimized find and path compression....

vector<int> size(n);
vector<int> parent(n);
void initialization(int n){
    for(int i=0;i<n;++i){
      size[i] = 1;
      parent[i] = i;
    }
}
int find_optimized(int i){
  while(parent[i]!=i){
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}
void _union(int xr,int yr){
  if(size[xr]<size[yr]){
    parent[xr] = parent[yr];
    size[yr]+=size[xr];
  }else{
    parent[yr] = parent[xr];
    size[xr]+=size[yr];
  }
}
bool iscycle(vector<int> adj[],int v){
  for(int i=0;i<v;++i){
    for(int j=0;j<adj[i].size();++j){
      int x = find(i);
      int y = find(adj[i][j]);
      if(x==y){
        return true;
      }
      _union(x,y);
    }
  }
  return false;
}
