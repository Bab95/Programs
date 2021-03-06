/*
Given an array and q queries
queries are of two types find_sum(l,r) and update(i,v)
find_sum(l,r) => will find sum of array ranged from l to r
update(i,v) => update value at index i to v

*/

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
using namespace std;
struct segment_tree{
    int size;
    vector<long long int> sums;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        sums.assign(2*size,0);
    }
    //build segment tree from a given array.....
    void _build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        _build(a,2*x+1,lx,m);
        _build(a,2*x+2,m,rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }
    void build(vector<int>& a){
        _build(a,0,0,size);
    }
    void _set(int i,int v,int x,int lx,int rx){
        if(rx - lx==1){ //leaf node size_of_segment = 1...
            sums[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if(i<m){
            _set(i,v,2*x+1,lx,m);
        }else{
            _set(i,v,2*x+2,m,rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x + 2];
    }
    void set(int i,int v){
        _set(i,v,0,0,size);
    }
    long long int _sum(int l,int r,int x,int lx,int rx){
        if(lx>=r ||l>=rx){
            return 0;
        }
        if(lx>=l&&rx<=r){
            return sums[x];
        }
        int m = (lx + rx)/2;
        long long int s1 = _sum(l,r,2*x+1,lx,m);
        long long int s2 = _sum(l,r,2*x+2,m,rx);
        return s1 + s2;
    }
    long long int sum(int l,int r){
        return _sum(l,r,0,0,size);
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
            cout<<_st.sum(l,r)<<endl;
        }
    }
}
