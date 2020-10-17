#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;

struct kosaraju{
    vector<vector<int>> Graph;
    vector<vector<int>> _Graph;
    int N;
    int ans = 0;
    void build_graph(string& str){
        ans = 0;
        int n = str.length();
        _Graph.assign(n,vector<int>());
        N = n;
        Graph.assign(n,vector<int>());
        for(int i=0;i<str.length();++i){
            int u ,v;
            u = i;
            v = (i+1)%n;
            if(str[i]=='-'){
                Graph[u].push_back(v);
                Graph[v].push_back(u);
            }else if(str[i]=='>'){
                Graph[u].push_back(v);
            }else if(str[i]=='<'){
                Graph[v].push_back(u);
            }
        }
    }

    void getTranspose(){
        for(int i=0;i<N;++i){
            for(auto it:Graph[i]){
                _Graph[it].push_back(i);
            }
        }
    }

    void fillOrder(int v,vector<bool>& visited,stack<int>& stk){
        visited[v] = true;
        for(auto it:Graph[v]){
            if(!visited[it]){
                fillOrder(it,visited,stk);
            }
        }
        stk.push(v);
    }

    void dfs(int v,vector<bool>& visited,int& size){
        visited[v] = true;
        //current_component.push_back(v);
        size++;
        for(auto it:_Graph[v]){
            if(!visited[it]){
                dfs(it,visited,size);
            }
        }
    }

    void find_sc(){
        stack<int> stk;
        vector<bool> visited(N,false);

        for(int i=0;i<N;++i){
            if(!visited[i]){
                fillOrder(i,visited,stk);
            }
        }

        getTranspose();

        for(int i=0;i<N;++i){
            visited[i] = false;
        }

        while(!stk.empty()){
            int v = stk.top();
            stk.pop();
            if(!visited[v]){
                int size = 0;
                dfs(v,visited,size);
                if(size>1){
                    ans+=size;
                }
            }
        }
    }
    void print(){
        for(int i=0;i<N;++i){
            cout<<i<<"-->";
            for(auto it:Graph[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
};
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    kosaraju kk;
    kk.build_graph(str);
    //kk.print();
    kk.find_sc();
    cout<<kk.ans<<endl;
    //cout<<"------------------"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}