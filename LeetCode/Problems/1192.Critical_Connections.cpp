class Solution {
public:
    int timer = 0;
    void dfs(vector<vector<int> >& graph,int node,int parent,vector<int>& low,vector<int>& in,vector<bool>& visited,vector<vector<int> >& ans){
        visited[node] = true;
        low[node] = timer;
        in[node] = timer;
        timer++;
        for(auto child : graph[node]){
            if(child==parent){
                continue;
            }
            if(visited[child]){
                //back edge.....
                low[node] = min(low[node],in[child]);
            }else{
                dfs(graph,child,node,low,in,visited,ans);
                if(low[child]>in[node]){
                    ans.push_back({node,child});
                }
                low[node] = min(low[node],low[child]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int> > graph(n,vector<int>());
        for(auto it : connections){
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }
        vector<int> low(n,0);
        vector<int> in(n,0);
        vector<vector<int> > ans;
        ans.reserve(connections.size());
        vector<bool> visited(n,false);
        dfs(graph,0,-1,low,in,visited,ans);
        return ans;
    }
};
