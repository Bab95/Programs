class Solution {
public:
    struct hash_pair {
    template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    void dfs(vector<unordered_set<int> >& graph,unordered_set<int>& visited,int i,int& size){
        visited.insert(i);
        size++;
        for(auto it=graph[i].begin();it!=graph[i].end();++it){
            int child = *it;
            if(visited.count(child)==0){
                dfs(graph,visited,child,size);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<pair<int,int>,int,hash_pair> mmap;
        unordered_map<int,pair<int,int> > mmap2;
        int index = 0;
        for(auto it : stones){
            mmap.insert({make_pair(it[0],it[1]),index});
            index++;
        }
        unordered_map<int,vector<int> > row,col;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            auto a = it->first;
            //auto b = it->second;
            row[a.first].push_back(it->second);
            col[a.second].push_back(it->second);
        }
        vector<unordered_set<int> > graph(mmap.size(),unordered_set<int>());
        for(auto it : stones){
            pair<int,int> p = make_pair(it[0],it[1]);
            int ind = mmap[p];
            int r = it[0];
            int c = it[1];
            for(auto i=row[r].begin();i!=row[r].end();++i){
                graph[ind].insert(*i);
            }
            for(auto i=col[c].begin();i!=col[c].end();++i){
                graph[ind].insert(*i);
            }
        }

        unordered_set<int> visited;
        int total_stones = mmap.size();
        int connected = 0;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            int current = it->second;
            if(visited.count(current)==0){
                int _current = 0;
                dfs(graph,visited,current,_current);
                cout<<_current<<endl;
                connected += (_current-1);
            }
        }

        return connected;
    }
};
