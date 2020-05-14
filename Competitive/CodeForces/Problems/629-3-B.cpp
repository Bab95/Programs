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
ll nc2(ll n){
  if(n%2==0){
    return n/2*(n-1);
  }
  return (n-1)/2*n;
}
void generateString(ll n,ll k,string& ans,ll size,ll bs){
  if(bs==0){
    if(ans.length()==size){
      return;
    }else{
      while(ans.length()<size){
        ans.pb('a');
      }
      return;
    }
  }
  if(ans.length()==size){
    return;
  }
  if(bs==2){
    ll total = nc2(n);
    if(k<=(total-n-1)){
      ans.pb('a');
      generateString(n-1,k,ans,size);
      return;
    }else{
        ans.pb('b');
        bs--;
        generateString(n-1,k-(n-1),ans,bs);
    }
  }else{
    //bs == 1
    for(int i=ans.length()-1,j=0;i<size;++i,++j){
      if(j==k){
        ans.pb('b');
      }else{
        ans.pb('a');
      }
    }
    return;
  }
}
void solve(){
    ll n,k;
    cin>>n>>k;
    string ans;
    generateString(n,k,ans,n,2);
    cout<<ans<<endl;
}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
