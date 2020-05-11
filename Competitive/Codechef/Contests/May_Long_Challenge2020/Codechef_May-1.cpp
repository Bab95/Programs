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
void generatePrimes(){

}
void swap(int *a,int *b){
    int tmp = *a;
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    input(arr,n);
    int amax = INT_MIN;
    int amin = INT_MAX;
    int current = 1;
    vector<int> segments;
    for(int i=1;i<n;++i){
      if(arr[i]-arr[i-1]<=2){
        current++;
      }else{
        segments.pb(current);
        current = 1;
      }
    }
    //if(arr[n-1]-arr[n-2]<=2){
    segments.pb(current);
    //}
    for(int i=0;i<segments.size();++i){
      amax = max(segments[i],amax);
      amin = min(segments[i],amin);
    }
    cout<<amin<<" "<<amax<<endl;
}
int main(){
    speed;
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    #endif // !ONLINE_JUDGE
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
