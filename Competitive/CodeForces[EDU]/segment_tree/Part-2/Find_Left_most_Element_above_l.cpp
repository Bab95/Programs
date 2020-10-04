#include <iostream>
#include <vector>
#include <algorithm>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct segment_tree{
    int size;
    vector<int> max_values;
    int NEUTRAL_ELEMENT = INT_MIN;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        max_values.assign(2*size,NEUTRAL_ELEMENT);
    }
    int left(int x){
        return 2*x + 1;
    }
    int right(int x){
        return 2*x + 2;
    }
    void build_tree(vector<int>& a,int x,int lx,int rx){
        //each node will store maximum of that segment......
        if(rx-lx==1){
            if(lx<(int)a.size()){
                max_values[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build_tree(a,left(x),lx,m);
        build_tree(a,right(x),m,rx);
        max_values[x] = max(max_values[left(x)],max_values[right(x)]);
    }
    void build_segment_tree(vector<int>& a){
        build_tree(a,0,0,size);
        return;
    }

    void set_value(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            max_values[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set_value(i,v,left(x),lx,m);
        }else{
            set_value(i,v,right(x),m,rx);
        }
        max_values[x] = max(max_values[left(x)],max_values[right(x)]);
    }
    void set(int i,int v){
        return set_value(i,v,0,0,size);
    }
    int find_left_most_above_util(int val,int l,int x,int lx,int rx){
        if(max_values[x]<val){
            return -1;
        }
        if(rx<=l){
            return -1;
        }
        if(rx-lx==1){
            return lx;
        }
        int m = (lx+rx)/2;
        int left_most_element = find_left_most_above_util(val,l,left(x),lx,m);
        if(left_most_element==-1){
            return find_left_most_above_util(val,l,right(x),m,rx);
        }
        return left_most_element;
    }
    int find_left_most_above(int val,int l){
        return find_left_most_above_util(val,l,0,0,size);
    }
};
int main(){
    speed
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    segment_tree st;
    st.init(n);
    st.build_segment_tree(a);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }else{
            int x,l;
            cin>>x>>l;
            cout<<st.find_left_most_above(x,l)<<endl;
        }
    }
    return 0;
}
