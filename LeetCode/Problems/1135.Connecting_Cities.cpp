class Solution {
public:
    struct krushkal{
        int cities;
        vector<vector<int> > graph;
        vector<int> parent;
        vector<int> rank;
        void init(int n,vector<vector<int>>& connections){
            cities = n;
            graph = connections;
            rank.assign(n+1,0);
            parent.assign(n+1,0);
            for(int i=0;i<parent.size();++i){
                parent[i] = i;
            }
        }
        void union_set(int a,int b){
            a = find_parent(a);
            b = find_parent(b);
            if(a!=b){
                if(rank[a]<rank[b]){
                    swap(a,b);
                }
                parent[b] = a;
                if(rank[a]==rank[b]){
                    rank[a] += 1;
                }
            }
        }
        int find_parent(int v){
            if(parent[v]==v){
                return v;
            }
            return parent[v] = find_parent(parent[v]);
        }
        int find_min_cost(){
            int min_cost = 0;
            for(auto it : graph){
                if(find_parent(it[0])!=find_parent(it[1])){
                    min_cost += it[2];
                    union_set(it[0],it[1]);
                }
            }
            int current = parent[1];
            for(int i=1;i<parent.size();++i){
                cout<<parent[i]<<" ";
            }
            for(int i=1;i<parent.size();++i){
                if(current!=parent[i]){
                    return -1;
                }
            }
            return min_cost;
        }
    };
    int minimumCost(int N, vector<vector<int>>& connections) {
        if(connections.size()==N-1){
            //already a MST
            int min_cost = 0;
            for(auto it:connections){
                min_cost += it[2];
            }
            return min_cost;
        }
        sort(connections.begin(),connections.end(),[](auto const& a,auto const& b){
            return a[2]<b[2];
        });
        krushkal solver;
        solver.init(N,connections);
        return solver.find_min_cost();
    }
};
