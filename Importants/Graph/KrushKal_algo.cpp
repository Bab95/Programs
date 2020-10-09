#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,weight;
    bool operator<(edge const& second){
        return weight<second.weight;
    }
};
struct krushkal{
    vector<int> parent,rank;
    void init(vector<edge>& graph){
        parent.assign(graph.size(),0);
        rank.assign(graph.size(),0);
        _make_set(graph.size());
    }
    void _make_set(int n){
        for(int i=0;i<n;++i){
            make_set(i);
        }
    }
    void make_set(int v){
        parent[v] = v;
    }
    int find_set(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v] = find_set(v);
    }
    void union_set(int a,int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b] = a;
            if(rank[a]==rank[b]){
                rank[a]++;
            }
        }
    }
    vector<edge> find_mst(vector<edge>& graph){
        init(graph);
        sort(graph.begin(),graph.end());
        vector<edge> mst;
        for(auto it:graph){
            if(find_set(it.u)!=find_set(it.v)){
                mst.push_back(edge);
                union_set(it.u,it.v);
            }
        }
        return mst;
    }
    int calculate_cost(vector<edge>& mst){
        int cost = 0;
        for(auto it:mst){
            cost += it.weight;
        }
    }
};
int main(){
    vector<edge> graph;
    krushkal kk;
    vector<edge> mst = kk.find_mst(graph);
    int cost = kk.calculate_cost(mst);
    return 0;
}