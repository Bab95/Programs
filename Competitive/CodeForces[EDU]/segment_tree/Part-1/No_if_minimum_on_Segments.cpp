#include <bits/stdc++.h>
#define endl "\n"
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct segment_tree{
    vector<pair<int,int> > values;
    int size;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        values.assign(2*size,{0,0});
    }
    void _set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x] = {v,1};
            return;
        }
        int m = (lx + rx)/2;
        if(i<m){
            _set(i,v,2*x+1,lx,m);
        }else{
            _set(i,v,2*x+2,m,rx);
        }
        if(values[2*x+1].first<values[2*x+2].first){
            values[x].first = values[2*x+1].first;
            values[x].second = values[2*x+1].second;
        }else if(values[2*x+2].first<values[2*x+1].first){
            values[x].first = values[2*x+2].first;
            values[x].second = values[2*x+2].second;
        }else if(values[2*x+1].first==values[2*x+2].first){
            values[x].first = values[2*x+1].first;
            values[x].second = values[2*x+1].second + values[2*x+2].second; 
        }
    }
    void set(int i,int v){
        _set(i,v,0,0,size);
    }
    void _build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                values[x] = {a[lx],1};
            }
            return;
        }
        int m = (lx+rx)/2;
        _build(a,2*x+1,lx,m);
        _build(a,2*x+2,m,rx);
        if(values[2*x+1].first<values[2*x+2].first){
            values[x].first = values[2*x+1].first;
            values[x].second = values[2*x+1].second;
        }else if(values[2*x+2].first<values[2*x+1].first){
            values[x].first = values[2*x+2].first;
            values[x].second = values[2*x+2].second;
        }else if(values[2*x+1].first==values[2*x+2].first){
            values[x].first = values[2*x+1].first;
            values[x].second = values[2*x+1].second + values[2*x+2].second; 
        }
    }
    void build(vector<int>& a){
        _build(a,0,0,size);
    }
    pair<int,int> count_min(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return {INT_MAX,-1};
        }
        if(lx>=l&&rx<=r){
            return values[x];
        }
        int m = (lx+rx)/2;
        pair<int,int> p1 = count_min(l,r,2*x+1,lx,m);
        pair<int,int> p2 = count_min(l,r,2*x+2,m,rx);
        if(p1.first<p2.first){
            return p1;
        }else if(p1.first>p2.first){
            return p2;
        }else if(p1.first==p2.first){
            return {p1.first,p1.second+p2.second};
        }
        return {INT_MAX,0};
    }
    pair<int,int> get_min_count(int l,int r){
        return count_min(l,r,0,0,size);
    }
};
int main(){
    speed;
    int n, m, v;
    cin>>n>>m;
    struct segment_tree _st;
    _st.init(n);
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    _st.build(arr);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            _st.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            pair<int,int> ans = _st.get_min_count(l,r);
        
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
}