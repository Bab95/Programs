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
void dfs(vector<vector<ll> >& graph,vector<ll>& path,ll i,ll n){
	path.pb(i);
	if(i==n){
		for(int i=0;i<path.size();++i){
			cout<<path[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int j=0;j<graph[i].size();++j){
		dfs(graph,path,graph[i][j],n);
	}
	path.pop_back();
}
void solve(){
		ll n;
		cin>>n;
		ll v;
		vector<vector<ll> > graph(n+1,vector<ll>());
		fo(i,2,n){
			cin>>v;
			graph[v].pb(i);
		}

		vector<ll> path;
		dfs(graph,path,1,n);
}
int main(){
		speed;
		solve();
}
