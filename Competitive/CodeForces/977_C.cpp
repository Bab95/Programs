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
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
typedef long long int ll;
typedef unsigned long long int ulli;
#define M 10e9
using namespace std;
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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end());
    //Boundary cases..
    if(k==0){
        if(arr[0]>=2){
            cout<<arr[0]-1;
        }else{
            cout<<-1<<endl;
        }
        return;
    }
    if(k==n){
        cout<<arr[n-1]<<endl;
        return;
    }
    int ans = arr[k-1];
    if(arr[k]==ans){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}
int main(){
    solve();
}