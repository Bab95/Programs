#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll bfs(vector<vector<int> >& graph,int node,vector<int>& nodes){
    queue<int> q;
    q.push(node);
    int level = 0;
    ll ans = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<q.size();++i){
            int current = q.front();
            q.pop();
            if(level%2==0){
                ans += (ll)nodes[current];
            }
            for(int j=0;j<graph[current].size();++j){
                int child = graph[current][j];
                q.push(child);
            }
        }
        level++;
    }
    return ans;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> nodes(n+1),query(q);
    for(int i=1;i<=n;++i){
        cin>>nodes[i];
    }
    vector<vector<int> > graph(n+1,vector<int>());
    int a,b;
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        graph[a].push_back(b);
    }

    for(int i=0;i<q;++i){
        cin>>query[i];
    }
    
    sort(query.begin(),query.end());
    int first_even=-1,first_odd=-1;
    for(int i=0;i<q;++i){
        if(query[i]%2==0&&first_even==-1){
            first_even = query[i];
        }else if(query[i]%2==1&&first_odd==-1){
            first_odd = query[i];
        }
        if(first_even!=-1&&first_even!=-1){
            break;
        }
    }
    ll esum = 0,osum = 0;
    if(first_even!=-1){
        esum = bfs(graph,first_even,nodes);
    }
    if(first_odd!=-1){
        osum = bfs(graph,first_odd,nodes);
    }
    a = min(first_even,first_odd);
    b = max(first_even,first_odd); 
    for(int i=1;i<nodes.size();++i){
        if(i==first_even){
            cout<<esum<<" ";
        }else if(i==first_odd){
            cout<<osum<<" ";
        }else{
           cout<<0<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}