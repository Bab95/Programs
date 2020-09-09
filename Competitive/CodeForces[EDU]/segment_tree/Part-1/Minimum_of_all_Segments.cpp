#include <bits/stdc++.h>
#define endl "\n"
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct segment_tree{
    int size;
    vector<int> values;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        values.assign(2*size,0);   
    }
    void _set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            _set(i,v,2*x+1,lx,m);
        }else{
            _set(i,v,2*x+2,m,rx);
        }
        values[x] = min(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v){
        _set(i,v,0,0,size);
    }
    void _build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                values[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        _build(a,2*x+1,lx,m);
        _build(a,2*x+2,m,rx);
        values[x] = min(values[2*x+1],values[2*x+2]);
    }
    void build(vector<int>& a){
        _build(a,0,0,size);
    }
    int find_min(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx){
            return INT_MAX;
        }
        if(lx>=l&&rx<=r){
            return values[x];
        }
        int m = (lx+rx)/2;
        int v1 = find_min(l,r,2*x+1,lx,m);
        int v2 = find_min(l,r,2*x+2,m,rx);
        return min(v1,v2);
    }
    int get_min(int l,int r){
        return find_min(l,r,0,0,size);
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
            cout<<_st.get_min(l,r)<<endl;
        }
    }
}