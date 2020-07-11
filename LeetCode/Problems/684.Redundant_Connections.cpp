class Solution {
public:
    int timer = 0;
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    unordered_map<pair<int,int>,int,hash_pair> index_of;
    void dfs(vector<vector<int> >& graph,vector<bool>& visited,vector<int>& in,vector<int>& low,int node,int parent,pair<int,int>& ans){
        visited[node] = true;
        in[node] = timer;
        low[node] = timer;
        timer++;
        for(auto child : graph[node]){
            if(child==parent){
                continue;
            }else if(visited[child]){
                //backward edge....
                pair<int,int> current;
                current.first = min(node,child);
                current.second = max(node,child);
                if(index_of[current]>index_of[ans]){
                    ans = current;
                }
                low[node] = min(low[node],in[child]);
            }else{
                //forward edge...
                dfs(graph,visited,in,low,child,node,ans);
                //we are not searching for bridges....

                low[node] = min(low[node],low[child]);
            }
        }
    }
    void reinitialize(vector<bool>& visited,vector<int>& in,vector<int>& low){
        std::fill(visited.begin(),visited.end(),false);
        std::fill(in.begin(),in.end(),0);
        std::fill(low.begin(),low.end(),0);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int> > graph(edges.size()+1,vector<int>());
        int index = 0;
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            index_of[make_pair(it[0],it[1])] = index++;
        }
        vector<bool> visited(n+1,false);
        vector<int> in(n+1,0);
        vector<int> low(n+1,0);
        pair<int,int> ans;
        for(int i=1;i<=n;++i){
            reinitialize(visited,in,low);
            dfs(graph,visited,in,low,i,-1,ans);
        }

        vector<int> res = {ans.first,ans.second};
        return res;
    }
};
