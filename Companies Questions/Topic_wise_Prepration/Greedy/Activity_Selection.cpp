/*
Problem Statement: Given Jobs{start,end} find the maximum no of
Jobs a person can perform
*/

#include <bits/stdc++.h>
using namespace std;
void find_max_jobs(vector<int>& start,vector<int>& end){
    vector<pair<int,pair<int,int>> > jobs(start.size());
    for(int i=0;i<start.size();++i){
        jobs[i].first = i+1;
        jobs[i].second.first = start[i];
        jobs[i].second.second = end[i];
    }
    sort(jobs.begin(),jobs.end(),[](pair<int,pair<int,int>> const& a,pair<int,pair<int,int>> const& b){
        if(a.second.second==b.second.second){
            return a.second.first>b.second.first;
        }
        return a.second.second<b.second.second;
    });
    auto current = jobs[0];
    vector<int> ans;
    ans.push_back(jobs[0].first);
    for(int i=1;i<jobs.size();++i){
        if(jobs[i].second.first<current.second.second){
            continue;
        }else if(jobs[i].second.first>=current.second.second){
            ans.push_back(jobs[i].first);
            current = jobs[i];
        }
    }
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0;i<n;++i){
        cin>>start[i];
    }
    for(int i=0;i<n;++i){
        cin>>end[i];
    }
    find_max_jobs(start,end);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}