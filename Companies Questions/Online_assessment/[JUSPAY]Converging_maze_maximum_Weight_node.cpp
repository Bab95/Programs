#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
void buildgraph(vector<int>& arr,unordered_map<int,int>& graph){
    for(int i=0;i<arr.size();++i){
        if(arr[i]==-1){
            continue;
        }
        graph[arr[i]]+=i;
    }
    pair<int,int> ans;
    ans.first = -1;
    ans.second = 0;
    for(auto it=graph.begin();it!=graph.end();++it){
        //cout<<it->first<<" --> "<<it->second<<endl;
        if(it->second>ans.second){
            ans.second = it->second;
            ans.first = it->first;
        }else if(it->second==ans.second){
            ans.first = min(ans.first,it->first);
        }
    }
    cout<<ans.first<<endl;
}

int main(){
    unordered_map<int,int> graph;
    vector<int> arr = {4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21};
    vector<int> brr = {5,3,3,9,8,4,1,3,7,0,11,10,10,10};
    buildgraph(brr,graph);
    graph.clear();
    cout<<"-----END------"<<endl;
    buildgraph(arr,graph);
}
