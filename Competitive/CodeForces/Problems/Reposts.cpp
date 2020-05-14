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
void dfs(vector<vector<int> >& graph,int start,int* ans,int chain){
	if(chain>*ans){
		*ans = chain;
	}
	for(int i=0;i<graph[start].size();++i){
		//if(!visited[graph[i][start]]){
			dfs(graph,graph[start][i],ans,chain+1);
		//}
	}
}
void tolower(string& s){
	//cout<<"in "<<s<<endl;;
	for(int i=0;i<s.length();++i){
		if(s[i]<=90){
			s[i] = s[i]-'A'+'a';
		}
	}
	//cout<<"out "<<s<<endl;
}
void solve(){
		ll n;
		cin>>n;
		unordered_map<string,int > mmap;
		string n1,rep,n2;
		vector<vector<int> > graph;
		int index = 0;
		vector<int> tmp;
		for(int i=0;i<n;++i){
			cin>>n1;
			cin>>rep;
			cin>>n2;
			tolower(n1);
			tolower(n2);
			if(mmap.find(n1)==mmap.end()){
				mmap[n1] = index;
				index++;
			}
			if(graph.size()<index){
				graph.pb(tmp);
			}
			if(mmap.find(n2)==mmap.end()){
				mmap[n2] = index;
				index++;
			}
			if(graph.size()<index){
				graph.pb(tmp);
			}
			graph[mmap[n2]].pb(mmap[n1]);
			//graph[mmap[n1]].pb(mmap[n2]);
		}

		int start = mmap["polycarp"];
		int ans = 0;
		//vector<bool> visited(index,false);
		dfs(graph,start,&ans,1);
		cout<<ans<<endl;
}
int main(){
		speed;
		solve();
}
