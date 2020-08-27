#include <bits/stdc++.h>

using namespace std;
const int _max = 1e5 + 5;
vector<int> graph[_max];
unordered_map<int,int> permutation;
int arr[_max];
bool visited[_max];
void dfs(int node,vector<int>& path){
   visited[node] = true;
   path.push_back(node);
   for(auto child:graph[node]){
       if(!visited[child]){
           dfs(child,path);
       }
   }
}
int main() {
    int n,m,a,b;
    cin>>n>>m;
    vector<int> path;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        permutation[a] = i;
        arr[i] = a;
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    for(size_t node=1;node<=n;++node){
        sort(graph[node].begin(),graph[node].end(),[](const int &a,const int &b){
            return permutation[a]<permutation[b];
        });
    }
    dfs(arr[0],path);
    bool flag = true;
    for(int i=0;i<n;++i){
        int node = path[i];
        if(permutation[node]!=i){
            flag = false;
            cout<<0<<endl;
            break;
        }
    }
    if(flag){
        cout<<1<<endl;
    }
    return 0;
}
