#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> r(n,0);
    for(int i=0;i<r.size();++i){
        cin>>r[i];
    }
    vector<vector<int> > change(n,vector<int>(m));
    for(int i=0;i<change.size();++i){
        for(int j=0;j<change[0].size();++j){
            cin>>change[i][j];
        }
    }
    vector<pair<int,int>> best_rating(n,{-1,0});
    vector<pair<int,int>> best_rank(n,{INT_MAX,0});
    for(int j=0;j<m;++j){
        priority_queue<pair<int,int> > pq;
    
        for(int i=0;i<n;++i){
            r[i] = r[i]+change[i][j];
            pq.push({r[i],i});
        }
        int prev_best = -1;
        int rank = 1;
        int count = 1;
        while(!pq.empty()){
            auto x = pq.top();
            //cout<<x.first<<" "<<x.second<<endl;
            pq.pop();
            
            if(best_rating[x.second].first<x.first){
                best_rating[x.second].first = x.first;
                best_rating[x.second].second = j+1;
            }
            if(prev_best==-1){
                rank = 1;
                count = 1;
                prev_best = x.first;
            }else if(prev_best==x.first){
                count++;
            }else if(prev_best!=x.first){
                rank += count;
                prev_best = x.first;
                count = 1;
            }
            if(best_rank[x.second].first>rank){
                best_rank[x.second].first = rank;
                best_rank[x.second].second = j+1;
            }
        }
        //cout<<endl;
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        if(best_rank[i].second!=best_rating[i].second){
            ans++;
        }
    }
    /*
    for(int i=0;i<best_rank.size();++i){
        cout<<best_rank[i].first<<" "<<best_rank[i].second<<endl;
    }
    cout<<"--------"<<endl;
    for(int i=0;i<best_rating.size();++i){
        cout<<best_rating[i].first<<" "<<best_rating[i].second<<endl;
    }*/
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}