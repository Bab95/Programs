class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<vector<pair<int,int> > > graph(n+1,vector<pair<int,int> >());
        for(auto it : flights){
            int from = it[0];
            int to = it[1];
            int cost = it[2];
            graph[from].push_back(make_pair(to,cost));
        }

        queue<vector<int> > q;
        q.push({src,0,-1});
        int mincost = INT_MAX;
        while(!q.empty()){
            vector<int> current = q.front();
            q.pop();
            int current_city = current[0];
            int current_cost = current[1];
            int current_stops = current[2];
            if(current_city==dst){
                mincost = min(mincost,current_cost);
                continue;
            }
            for(int i=0;i<graph[current_city].size();++i){
                if(current_stops+1<=K&&current_cost+graph[current_city][i].second<mincost){
                    q.push({graph[current_city][i].first,current_cost+graph[current_city][i].second,current_stops+1});
                }
            }
        }

        return mincost==INT_MAX?-1:mincost;
    }
};
