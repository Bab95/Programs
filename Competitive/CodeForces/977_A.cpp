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
    long long int n;
    int k;
    cin>>n>>k;
    int count = 0;
    while(n!=1&&count<k){
        if(n%10==0){
            n = n/10;
        }
        else{
            --n;
        }
        ++count;
    }
    cout<<n<<endl;
}
int main(){
    solve();
}