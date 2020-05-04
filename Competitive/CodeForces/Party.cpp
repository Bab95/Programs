#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#include <string.h>
#include <math.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap(ll *a,ll *b){
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void input(vector<ll>& arr,int n){
  fo(i,0,n-1){
    cin>>arr[i];
  }
}
void input(vector<ulli>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
ll max(ll a,ll b){
    return a>b?a:b;
}
ulli max(ulli a,ulli b){
    return a>b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void print(vector<ll>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int ans = 0;
void dfs(vector<vector<int> >& graph,int root,int x){
  ans = max(ans,x);
  for(int i=0;i<graph[root].size();++i){
    dfs(graph,graph[root][i],x+1);
  }
}
void solve(){
    ll n;
    cin>>n;
    //vector<ll> arr(n);
    vector<vector<int> > graph(n+1,vector<int>());
    vector<int> roots;
    ll v;
    for(int i=1;i<=n;++i){
      cin>>v;
      if(v==-1){
        roots.pb(i);
      }else{
        graph[v].pb(i);
      }
    }
    for(int i=0;i<roots.size();++i){
      dfs(graph,roots[i],1);
    }
    cout<<ans<<endl;
}
int main(){
    speed;
    solve();
}
