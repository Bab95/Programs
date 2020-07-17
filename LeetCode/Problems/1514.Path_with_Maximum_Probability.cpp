#define EPSILON 0.000001
class Solution {
public:
    void print(vector<vector<double> >& graph){
        for(int i=0;i<graph.size();++i){
            for(int j=0;j<graph[i].size();++j){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool equal(double a,double b){
        if(a-b<EPSILON){
            return true;
        }
        return false;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        vector<vector<int> > graph(n,vector<int>());

        for(int i=0;i<edges.size();++i){
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(i);
            graph[b].push_back(i);
        }
        vector<double> dist(n,-0.2);
        vector<bool> visited(n,false);
        dist[start] = 0;
        priority_queue<pair<double,int>> pq;
        pq.push(make_pair(1.0,start));
        visited[start] = true;
        while(!pq.empty()){
            pair<double,int> current = pq.top();
            pq.pop();
            visited[current.second] = true;
            for(int i=0;i<graph[current.second].size();++i){
                int edge = graph[current.second][i];
                int v = -1;
                if(current.second==edges[edge][0]){
                    v = edges[edge][1];
                }else{
                    v = edges[edge][0];
                }
                if(!visited[v]&&dist[v]<current.first*succProb[edge]){
                    dist[v] = current.first*succProb[edge];
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        if(dist[end]<0){
            return 0;
        }
        return dist[end];
    }
};
//not optimized solution using adjancy matrix....
#define EPSILON 0.000001
class Solution {
public:
    void print(vector<vector<double> >& graph){
        for(int i=0;i<graph.size();++i){
            for(int j=0;j<graph[i].size();++j){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool equal(double a,double b){
        if(a-b<EPSILON){
            return true;
        }
        return false;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        vector<vector<double> > graph(n,vector<double>(n,0));

        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]][edges[i][1]] = graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        //print(graph);
        vector<double> dist(n,-0.2);
        vector<bool> visited(n,false);
        dist[start] = 0;
        priority_queue<pair<double,int>> pq;
        pq.push(make_pair(1.0,start));
        visited[start] = true;
        while(!pq.empty()){
            pair<double,int> current = pq.top();
            pq.pop();
            visited[current.second] = true;
            for(int i=0;i<graph[current.second].size();++i){
                if(!equal(graph[current.second][i],0)&&!visited[i]){
                    if(current.first*graph[current.second][i]>dist[i]){
                        dist[i] = current.first*graph[current.second][i];
                        pq.push(make_pair(dist[i],i));
                    }
                }
            }
        }
        if(dist[end]<0){
            return 0;
        }
        return dist[end];
    }
};
