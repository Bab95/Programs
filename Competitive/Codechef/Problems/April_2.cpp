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
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
#define M 1000000007
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
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
bool decreasing(int const& a,int const& b){
    return a>b;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    sort(arr.begin(),arr.end(),decreasing);
    //print(arr,n);
    int profit = arr[0];
    for(int i=1;i<n;++i){
        profit += max(0,arr[i]-i);
        profit = profit % M;
    }
    cout<<profit<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}