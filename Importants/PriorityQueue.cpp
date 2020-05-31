#include <bits/stdc++.h>
using namespace std;
//Its exactly opposite as that of compare function in vectors....
struct compareMIN{
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.first>p2.first){
            return true;
        }
        return false;
    }
};
struct compareMAX{
  bool operator()(const pair<int,int>& p1,const pair<int,int>& p2){
    if(p1.first<p2.first){
      return true;
    }
    return false;
  }
};
bool mysortCompare(const pair<int,int>& p1,const pair<int,int>& p2){
    if(p1.first<p2.first){
        return true;
    }
    return false;
}
int main(){
    int n,a,b;
    cin>>n;
    vector<pair<int,int> > v;
    //MIN HEAP.................
    priority_queue<pair<int,int>,vector<pair<int,int> >,compare> pq;
    for(int i=0;i<n/2;++i){
        cin>>a>>b;
        pq.push(make_pair(a,b));
        v.push_back(make_pair(a,b));
    }
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    cout<<"------vector sorting------"<<endl;
    sort(v.begin(),v.end(),mysortCompare);
    for(auto it=v.begin();it!=v.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
