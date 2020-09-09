class Solution {
public:
    pair<int,int> bfs(int root,vector<vector<int>>& graph){
        queue<pair<int,int> > q;
        q.push({root,0});
        pair<int,int> ans = {-1,-1};
        vector<bool> visited(graph.size(),false);
        while(!q.empty()){
            auto current = q.front();
            cout<<current.first<<" ";
            visited[current.first] = true;
            if(current.second>ans.second){
                ans = current;
            }
            q.pop();
            for(auto child : graph[current.first]){
                if(!visited[child]){
                    q.push({child,current.second+1});
                }
            }
        }
        return ans;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size()+1,vector<int>());
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        pair<int,int> last = bfs(0,graph);
        pair<int,int> _last = bfs(last.first,graph);
        return _last.second;
    }
};
