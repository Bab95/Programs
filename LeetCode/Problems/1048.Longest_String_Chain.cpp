class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    bool isPredecessor(string& s1,string& s2){
        if(s1.length()==s2.length()+1){
            int i = 0,j=0;
            int insertion = 0;
            while(i<s1.length()&&j<s2.length()){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }else if(!insertion){
                    insertion++;
                    ++i;
                }else{
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    int dfs(int index,vector<vector<int> >& graph,vector<bool>& visited,vector<int>& dp){
        visited[index] = true;
        int max_chain = 0;
        for(int i=0;i<graph[index].size();++i){
            if(!visited[graph[index][i]]){
                max_chain = max(dfs(graph[index][i],graph,visited,dp),max_chain);
            }else{
                max_chain = max(max_chain,dp[graph[index][i]]);
            }
        }
        return dp[index] = max_chain+1;
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> mmap;
        int id = 1;
        for(int i=0;i<words.size();++i){
            mmap[words[i]] = id++;
        }
        vector<vector<int> > graph(id,vector<int>());
        vector<bool> visited(id,false);
        vector<int> dp(id,0);
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].length();++j){
                string tmp = words[i].substr(0,j)+words[i].substr(j+1,words[i].length()-(j+1));
                if(mmap.find(tmp)!=mmap.end()){
                    int u = mmap[words[i]];
                    int v = mmap[tmp];
                    graph[u].push_back(v);
                }
            }
        }
        int max_chain = 0;
        for(int i=1;i<id;++i){
            if(!visited[i]){
                max_chain = max(dfs(i,graph,visited,dp),max_chain);
            }
        }
        return max_chain;
    }
};
