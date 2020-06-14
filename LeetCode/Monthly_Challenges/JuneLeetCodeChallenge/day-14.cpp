class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int> > > graph(n+1,vector<vector<int> >());
        for(int i=0;i<flights.size();++i){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            graph[from].push_back({to,cost,0});
        }

        queue<vector<int> > q;
        q.push({src,0,-1});
        int mincost = INT_MAX;
        while(!q.empty()){
            vector<int> current = q.front();
            q.pop();
            if(current[0]==dst){
                if(current[1]<mincost){
                    mincost = current[1];
                    continue;
                }
            }
            for(int i=0;i<graph[current[0]].size();++i){
                if(current[2]+1<=K&&current[1]+graph[current[0]][i][1]<mincost){
                    q.push({graph[current[0]][i][0],current[1]+graph[current[0]][i][1],current[2]+1});
                }
            }
        }
        return mincost==INT_MAX?-1:mincost;

    }
};
