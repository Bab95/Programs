#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> >& graph,int node,int& c1,int& c2,vector<bool>& visited,bool level){
    visited[node] = true;
    if(level){
        c1++;
    }else{
        c2++;
    }
    for(auto child :graph[node]){
        if(!visited[child]){
            dfs(graph,child,c1,c2,visited,!level);
        }
    }
}
int find_nearest(vector<vector<int> >& graph,string& s,int node,int& parent,int required){
    int d = INT_MAX;
    if(s[node-1]-'0'==required){
        swap(s[parent-1],s[node-1]);
        return 1;
    }
    for(auto child : graph[node]){
        
        int dis = 1 + find_nearest(graph,s,child,parent,required);
        d = min(d,dis);
    }
    return 1 + d;
}
void color(vector<vector<int>>& graph,int& swaps,int current,vector<bool>& visited,int node,int required,string& s){
    visited[node] = true;
    if(current!=required){
        int _ss = INT_MAX;
        for(auto child:graph[node]){
            int _swaps = find_nearest(graph,s,child,node,required);
            _ss = min(_swaps,_ss);
        }
        swaps += _ss;
    }
    for(auto child : graph[node]){
        if(!visited[child]){
            int _color = s[child-1]-'0'; 
            color(graph,swaps,_color,visited,node,!required,s);
        }
    }

}
void solve(){
    int n,a,b;
    cin>>n;
    vector<vector<int> > graph(n+1,vector<int>());
    vector<bool> visited(n+1,false);
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    string s;
    cin>>s;
    int z = 0,o = 0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='1'){
            o++;
        }else{
            z++;
        }
    }
    bool level = true;
    int c1 = 0,c2 = 0;
    dfs(graph,1,c1,c2,visited,level);
    if((c1==o&&c2!=z)||(c1==z&&c2!=o)){
        cout<<-1<<endl;
    }
    int _root = 0;
    if(o<z){
        _root = 0;
    }else{
        _root = 1;
    }
    fill(visited.begin(),visited.end(),false);
    int swaps = 0;
    int current = s[0]-'0';
    color(graph,swaps,current,visited,1,_root,s);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}