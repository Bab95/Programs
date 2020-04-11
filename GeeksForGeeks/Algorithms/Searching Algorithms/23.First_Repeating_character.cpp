#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
using namespace std;
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    unordered_map<int,int> mmap;
    int ans = INT_MAX;
    fo(i,0,n-1){
        if(mmap.count(arr[i])==0){
            mmap[arr[i]] = i+1;
        }else{
            ans = min(mmap[arr[i]],ans);
        }
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}