class Solution {
public:
    void dfs(vector<vector<int> >& graph,int i,vector<bool>& visited){
        visited[i] = true;
        for(int j=0;j<graph[i].size();++j){
            if(!visited[graph[i][j]]){
                dfs(graph,graph[i][j],visited);
            }
        }
    }
    int compare_strings(string& s1,string& s2){
        int swaps = 0;
        int i = 0;
        while(i<s1.length()){
            if(s1[i]!=s2[i]){
                swaps++;
                if(swaps>2){
                    break;
                }
            }
            ++i;
        }
        return swaps;
    }
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<vector<int> > graph(n,vector<int>());
        vector<bool> marked(n,false);
        for(int i=0;i<n-1;++i){
            if(marked[i]){
                continue;
            }
            for(int j=i+1;j<n;++j){
                if(A[i].length()!=A[j].length()){
                    continue;
                }
                int swaps = compare_strings(A[i],A[j]);
                if(swaps>2){
                    continue;
                }else if(swaps==2){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }else if(swaps==0){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    marked[j] = true;
                }
            }
        }
        int groups = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(graph,i,visited);
                groups++;
            }
        }
        return groups;
    }
};
