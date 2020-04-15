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
int max(int a,int b){
    return a>b?a:b;
}
void solve(){
    int n;
    cin>>n;
    vector<int> ids(n);
    vector<int> sums(n);
    fo(i,0,n-1){
        cin>>ids[i]>>sums[i];
    }
    int result = 0;
    fo(i,0,n-1){
        result = result + ids[i] - sums[i];
    }
    cout<<result<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}