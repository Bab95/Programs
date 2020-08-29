#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
}
void solve(){
    int n;
    cin>>n;
    int a;
    unordered_map<int,int> mmap;
    for(int i=0;i<n;++i){
        cin>>a;
        mmap[a] += 1;
    }
    vector<int> arr;
    for(auto it=mmap.begin();it!=mmap.end();++it){
        arr.push_back(it->second);
    }
    mmap.clear();
    for(int i=0;i<arr.size();++i){
        mmap[arr[i]]+=1;
    }
    pair<int,int> ans={INT_MAX,INT_MIN};
    for(auto it=mmap.begin();it!=mmap.end();++it){
        if(it->second>ans.second){
            ans.second = it->second;
            ans.first = it->first;
        }else if(it->second==ans.second){
            ans.first = min(it->first,ans.first);
        }
    }
    cout<<ans.first<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}