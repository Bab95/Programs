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
bool leaf(vector<vector<int> >& graph,int i){
	if(graph[i].size()==0){
		//cout<<i<<" is a leaf"<<endl;
		return true;
	}
	return false;
}
void dfs(vector<vector<int> >& graph,int i,bool& is){
	//cout<<"dfs for"<<i<<endl;
	if(!leaf(graph,i)){
		int leaf_count = 0;
		for(int j=0;j<graph[i].size();++j){
			if(leaf(graph,graph[i][j])){
				leaf_count++;
			}
		}
		if(leaf_count<3){
			is = false;
			//cout<<"change"<<endl;
			return;
		}

		for(int j=0;j<graph[i].size();++j){
			if(!leaf(graph,graph[i][j])){
				dfs(graph,graph[i][j],is);
			}
		}
	}
}
void solve(){
		ll n;
		cin>>n;
		vector<vector<int> > graph(n+1,vector<int>());
		int u;
		for(int i=2;i<=n;++i){
			cin>>u;
			graph[u].pb(i);
		}
		//cout<<"n is"<<n<<endl;
		/*for(int i=1;i<graph.size();++i){
			cout<<i<<" :";
			for(int j=0;j<graph[i].size();++j){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}*/
		bool is = true;
		dfs(graph,1,is);
		if(is){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
}
int main(){
		speed;
		solve();

}
