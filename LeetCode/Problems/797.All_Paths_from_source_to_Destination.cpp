class Solution {
public:
    void dfs(vector<vector<int> >& graph,int node,vector<int>& path,vector<bool>& visited,vector<vector<int> >& ans,int destination){
        visited[node] = true;
        if(node==destination){
            ans.push_back(path);
            visited[node] = false;
            return;
        }
        for(auto child : graph[node]){
            if(!visited[child]){
                path.push_back(child);
                dfs(graph,child,path,visited,ans,destination);
                path.pop_back();
            }
        }
        visited[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //vector<vector<int> > graph(n,vector<int>());
        vector<vector<int> > ans;
        vector<int> path;
        int destination = graph.size()-1;
        vector<bool>visited(destination+1,false);
        path.push_back(0);
        dfs(graph,0,path,visited,ans,destination);
        return ans;
    }
};
