#include <bits/stdc++.h>
using namespace std;
struct edge{
    int w,to;
    edge():w(INT_MAX),to(-1){}
    bool operator<(edge const& second){
        return w<second.w;
    }
};
struct prims{
    vector<edge> min_edge;
    int nodes;
    
};
int main(){

}