#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int voter;
    unordered_map<int,int> mmap;
    for(int i=0;i<n1;i++){
        cin>>voter;
        mmap[voter]+=1;
    }
    for(int i=0;i<n2;++i){
        cin>>voter;
        mmap[voter]+=1;
    }
    for(int i=0;i<n3;++i){
        cin>>voter;
        mmap[voter]+=1;
    }
    int size = 0;
    vector<int> ans;
    for(auto it=mmap.begin();it!=mmap.end();++it){
        if(it->second>=2){
            ans.push_back(it->first);
            ++size;
        }
    }
    cout<<size<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
}
 int main(){
    solve();
 }
