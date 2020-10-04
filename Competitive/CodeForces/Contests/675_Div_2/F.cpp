#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
const int mod = 1e9 + 7;
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct segment_tree{
    int size;
    int NEUTRAL_ELEMENT = 1;
    vector<int> values;
    void init(int n){
        size = 1;
        while(size<n){
            size*=2;
        }
        values.assign(size,NEUTRAL_ELEMENT);
    }
    int left(int x){
        return 2*x + 1;
    }
    int right(int x){
        return 2*x + 2;
    }
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int lcm(int a,int b){
        if(a==1 ){
            return b;
        }
        if(b==1){
            return a;
        }
        long int tmp = (a*b)%mod;
        return tmp/(gcd(a,b)%mod);
    }
    void _build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                values[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        _build(a,left(x),lx,m);
        _build(a,right(x),m,rx);
        values[x] = lcm(values[left(x)],values[right(x)]);
    }
    void build(vector<int>& a){
        _build(a,0,0,size);
    }
    long int _query(int x,int lx,int rx,int l,int r){
        if(rx<=l||lx>=r){
            return NEUTRAL_ELEMENT;
        }
        if(lx>=l&&rx<=r){
            return values[x];
        }
        int m = (lx+rx)/2;
        long int left_ = _query(left(x),lx,m,l,r);
        long int right_ = _query(right(x),m,rx,l,r);
        return lcm(left_,right_);
    }
    long int query(int l,int r){
        return _query(0,0,size,l,r);
    }
    void print_Tree(){
        for(int i=0;i<size;++i){
            cout<<values[i]<<" ";
        }
        cout<<endl;
    }
};
void solve(){
    int n,q;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cin>>q;
    int last = 0;
    segment_tree st;
    st.init(n);
    st.build(a);
    while(q--){
        int x,y,l,r;
        cin>>x>>y;
        l = (last + x)%n + 1;
        r = (last + y)%n + 1;
        if(l>r){
            swap(l,r);
        }
        last = st.query(l-1,r);
        cout<<last<<endl;
    }
}
int main(){
    //speed
    solve();
    return 0;
}
