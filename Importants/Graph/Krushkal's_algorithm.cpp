#include <bits/stdc++.h>
using namespace std;
/*Krushkal Algorithm Normal Sorting and checking if a cycle is found*/
struct edge{
    int u,v;
    int weight;
    edge(int u,int v,int w):u(u),v(v),weight(w){}
    bool operator<(edge const& second){
        return weight<second.weight;
    }
};
void krushkal_algo(vector<edge>& graph){
    vector<edge> mst;
    vector<int> tree_id(graph.size());
    for(int i=0;i<graph.size();++i){
        tree_id[i] = i;
    }
    int cost = 0;
    sort(graph.begin(),graph.end());
    for(auto it : graph){
        if(tree_id[it.u]!=tree_id[it.v]){
            cost += it.weight;
            mst.push_back(it);
            int old_id = tree_id[it.u];
            int new_id = tree_id[it.v];
            //Merging operation.............
            for(int i=0;i<tree_id.size();++i){
                if(tree_id[i]==old_id){
                    tree_id[i] = new_id;
                }
            }
        }
    }
}
//TC : O(nlogn + n^2) 

/*Applying DSU and path compression*/
/*For initialization*/
void make_set(int v,vector<int>& parent,vector<int>& rank){
    parent[v] = v;
    rank[v] = 0;
}
int find_set(int v,vector<int>& parent){
    if(v==parent[v]){
        //its root itself
        return v;
    }
    return parent[v] = find_set(parent[v],parent);
}
void union_sets(int a,int b,vector<int>& parent,vector<int>& rank){
    a = find_set(a,parent);
    b = find_set(b,parent);
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        //b is rooted at a now.....
        parent[b] = a;
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}
void krushkal_algorithm_dsu(vector<edge>& graph){
    int n = graph.size();
    vector<int> parent(n);
    vector<int> rank(n);
    vector<edge> mst;
    for(int i=0;i<n;++i){
        make_set(i,parent,rank);
    }
    int cost = 0;
    sort(graph.begin(),graph.end());
    for(auto it : graph){
        if(find_set(it.u,parent)!=find_set(it.v,parent)){
            cost += it.weight;
            mst.push_back(it);
            union_sets(it.u,it.v,parent,rank);
        }
    }
}

int main(){

    vector<edge> graph;

}