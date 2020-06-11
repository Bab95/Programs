#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
void dfs(vector<vector<int> >& graph,int i,vector<bool>& visited,int& count){
    visited[i] = true;
    ++count;
    for(int j=0;j<graph[i].size();++j){
        if(!visited[graph[i][j]]){
            dfs(graph,graph[i][j],visited,count);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1,vector<int>());
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    vector<int> counts;
    ll ans = 1;
    int groups = 0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            int count = 0;
            ++groups;
            dfs(graph,i,visited,count);
            counts.push_back(count);
        }
    }
    ans = 1;
    for(int i=0;i<counts.size();++i){
        ans = ans*(ll)counts[i];
        ans = ans%mod;
    }
    cout<<groups<<" "<<ans<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
