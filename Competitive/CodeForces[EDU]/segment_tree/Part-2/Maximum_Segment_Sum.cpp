/*
In this problem, you need to write a segment tree to find the segment with the maximum sum.



*/

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
using namespace std;
struct item{
    long long seg,pref,suf,sum;
};
struct segmet_tree{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = {0,0,0,0};
    int left(int x){
        return 2*x + 1;
    }
    int right(int x){
        return 2*x + 2;
    }
    item single(int v){
        if(v>0){
            return {v,v,v,v};
        }else{
            return {0,0,0,v};
        }
    }
    item merge(item a,item b){
        return {
            max(a.seg,max(b.seg,a.suf+b.pref)),
            max(a.pref,a.sum+b.pref),
            max(b.sum+a.suf,b.suf),
            a.sum + b.sum
        };
    }
    void _build(vector<int>& a,int x,int lx,int rx){
        if(rx - lx==1){
            if(lx<(int)a.size()){
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        _build(a,left(x),lx,m);
        _build(a,right(x),m,rx);
        values[x] = merge(values[left(x)],values[right(x)]);
    }
    void build(vector<int>& a){
        _build(a,0,0,size);
    }
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        values.resize(2*size);
    }
    void _set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            _set(i,v,left(x),lx,m);
        }else{
            _set(i,v,right(x),m,rx);
        }
        values[x] = merge(values[left(x)],values[right(x)]);
    }
    void set(int i,int v){
        _set(i,v,0,0,size);
    }
    item _calc(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return NEUTRAL_ELEMENT;
        }
        if(lx>=l&&rx<=r){
            return values[x];
        }
        int m = (lx+rx)/2;
        item i1 = _calc(l,r,left(x),lx,m);
        item i2 = _calc(l,r,right(x),m,rx);
        return  merge(i1,i2);
    }
    item calc(int l,int r){
        return _calc(l,r,0,0,size);
    }
};
int main(){
    speed;
    int n,m,i,v;
    cin>>n>>m;
    segmet_tree seg_tree;
    seg_tree.init(n);
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    seg_tree.build(arr);
    cout << seg_tree.calc(0,n).seg<<endl;
    while(m--){
        cin>>i>>v;
        seg_tree.set(i,v);
        cout<<seg_tree.calc(0,n).seg<<endl;
    }
    return 0;
}
/*

seg1   seg2
pref1  pref2
suff1  suff2

seg = max(seg1,seg2,suff1+pref2)

pref = max(pref1,sub_seg1+pref2)

suff = max(suff2,sub_seg2 + suff1);

max_subsegment(l,r)

*/
