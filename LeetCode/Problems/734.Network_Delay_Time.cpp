class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int> >  graph(N+1,vector<int>(N+1,INT_MAX));
        vector<bool> visited(N+1,false);
        vector<int> dist(N+1,INT_MAX);

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u][v] = w;
            //graph[v][u] = w;
        }

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        pq.push(make_pair(0,K));
        dist[K] = 0;
        while(!pq.empty()){
            pair<int,int> tmp = pq.top();
            pq.pop();
            for(int i=1;i<=N;++i){
                if(graph[tmp.second][i]!=INT_MAX&&!visited[i]&&dist[i]>tmp.first+graph[tmp.second][i]){
                    dist[i] = tmp.first+graph[tmp.second][i];
                    pq.push(make_pair(dist[i],i));
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<dist.size();++i){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
