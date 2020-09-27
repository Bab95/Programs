class Solution {
public:
    void dfs(vector<vector<int>>& graph,int node,vector<bool>& visited){
        visited[node] = true;
        for(auto &child : graph[node]){
            if(!visited[child]){
                dfs(graph,child,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int> > graph(n,vector<int>());
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int ans = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ans++;
                dfs(graph,i,visited);
            }
        }
        return ans;
    }
};
