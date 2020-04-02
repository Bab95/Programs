#include <iostream>
#include <unordered_map>
#include <vector>
#define INT_MAX 1000000
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    input(arr,n);
    unordered_map<int,pair<int,int> > map;

    for(int i=0;i<n;i++){
        if(map.find(arr[i])==map.end()){
            pair<int,int> p;
            p.first = i;
            p.second = 1;
            map[arr[i]] = p;
        }else{
            map[arr[i]].second += 1;
        }
    }

    unordered_map<int,pair<int,int> >::iterator itr;
    int min_index = INT_MAX;
    for(itr=map.begin();itr!=map.end();++itr){
        //cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
        if(itr->second.second==k){
            min_index = min(min_index,itr->second.first);
        }
    }
    if(min_index==INT_MAX){
        cout<<"-1"<<endl;
        return;
    }
    cout<<arr[min_index]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
