#include <bits/stdc++.h>
using namespace std;
struct graph{
    vector<vector<int> > connections;
    vector<bool> visited;
    int mod = 1e9+7;
    int nodes;
    void init(int n){
        connections.assign(n+1,vector<int>());
        visited.assign(n+1,false);
        nodes = n;
    }
    void add(int a,int b){
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    void dfs(int v,int& size){
        size += 1;
        visited[v] = true;
        for(auto child : connections[v]){
            if(!visited[child]){
                dfs(child,size);
            }
        }
    }
    pair<int,long> find_connected_components(){
        pair<int,long> ans;
        ans.second = 1;
        for(int i=1;i<=nodes;++i){
            if(!visited[i]){
                int size = 0;
                ans.first++;
                dfs(i,size);
                ans.second *= (long)size;
                if(ans.second>mod){
                    ans.second %= mod;
                }
            }
        }
        return ans;
    }
};
void solve(){
    int m,n;
    cin>>n>>m;
    graph Graph;
    Graph.init(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        Graph.add(a,b);
    }
    pair<int,long> ans = Graph.find_connected_components();
    cout<<ans.first<<" "<<ans.second<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}