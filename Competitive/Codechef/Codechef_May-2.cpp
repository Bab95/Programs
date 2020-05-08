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
void debugGraph(vector<vector<int> >& graph){
  for(int i=0;i<graph.size();++i){
			cout<<i<<" :";
			for(int j=0;j<graph[i].size();++j){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
}
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
void solve(){
    int q,n;
    cin>>n>>q;
    string s;
    cin>>s;
    unordered_map<char,int> mmap;
    for(int i=0;i<s.length();++i){
      mmap[s[i]]+=1;
    }
    int centers;
    while(q--){
      vector<int> rem;
      cin>>centers;
      for(auto it=mmap.begin();it!=mmap.end();++it){
        if(centers<it->second){
          rem.push_back(it->second-centers);
        }
      }
      int ans = 0;
      for(int i=0;i<rem.size();++i){
        ans+=rem[i];
      }
      cout<<ans<<endl;
    }

}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
