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
bool mycompare(pair<int,int> const& p1,pair<int,int> const &p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    unordered_map<int,int> mmap;
    fo(i,0,arr.size()-1){
        mmap[arr[i]]++;
    }
    vector<pair<int,int> > result;
    result.reserve(mmap.size());
    copy(mmap.begin(),mmap.end(),back_inserter(result));
    sort(result.begin(),result.end(),mycompare);
    fo(i,0,result.size()-1){
        int count = 0;
        while(count<result[i].second){
            cout<<result[i].first<<" ";
            ++count;
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}