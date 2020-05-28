class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> group(N+1,-1);
        vector<vector<int> > graph(N+1,vector<int>());
        for(int i=0;i<dislikes.size();++i){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        /*for(int i=1;i<=N;++i){
            cout<<i<<" :";
            for(int j=0;j<graph[i].size();++i){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=N;++i){
            if(group[i]==-1){
                int src = i;

                group[src] = 1;
                queue<int> q;
                q.push(src);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int v=0;v<graph[u].size();++v){
                        if(group[graph[u][v]]==-1){
                            group[graph[u][v]] = !group[u];
                            q.push(graph[u][v]);
                        }else if(group[graph[u][v]]==group[u]){
                            //cout<<u<<" "<<graph[u][v]<<endl;
                            return false;
                        }
                    }
                }
            }
        }
        /*for(int i=1;i<=N;++i){
            cout<<group[i]<<" "<<endl;
        }*/
        return true;
    }
};
