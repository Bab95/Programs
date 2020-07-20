#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int l;
    cin>>l;
    string s;
    cin>>s;
    if(l%2==1){
        cout<<"NO"<<endl;
        return;
    }
    unordered_map<char,int> mmap;
    for(auto c : s){
        mmap[c] += 1;
    }
    for(auto it=mmap.begin();it!=mmap.end();++it){
        if(it->second%2==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
