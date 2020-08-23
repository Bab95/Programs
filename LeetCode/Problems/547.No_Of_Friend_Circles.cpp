class Solution {
public:
    void dfs(vector<vector<int> >& graph,int node,vector<bool>& visited){
        visited[node] = true;
        for(auto child : graph[node]){
            if(!visited[child]){
                dfs(graph,child,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<vector<int> > graph(M.size(),vector<int>());
        for(int i=0;i<M.size();++i){
            for(int j=0;j<M[0].size();++j){
                if(i==j){
                    continue;
                }
                if(M[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<bool> visited(M.size(),false);
        for(int i=0;i<M.size();++i){
            if(!visited[i]){
                ans++;
                dfs(graph,i,visited);
            }
        }
        for(int i=0;i<M.size();++i){
            if(!visited[i]){
                ans++;
            }
        }
        return ans;
    }
};
