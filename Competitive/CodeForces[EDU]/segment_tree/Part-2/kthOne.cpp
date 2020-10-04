/*
given an array of 0 and 1's need to find the index of
kth one in array
given queries of two types
1 i : flip the element with index i
2 k :find the kth one from 0 given k will always be valid.


*/

#include <iostream>
#include <vector>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct segment_tree{
    vector<int> sum;
    int size;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        sum.assign(2*size,0);
    }
    int left(int x){
        return 2*x + 1;
    }
    int right(int x){
        return 2*x + 2;
    }
    //Building functions.......................
    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                //x is index in tree and lx is value that should be
                //on the leaf node.......
                sum[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,left(x),lx,m);
        build(a,right(x),m,rx);
        sum[x] = sum[left(x)] + sum[right(x)];
    }
    void build_segment_tree(vector<int>& a){
        build(a,0,0,size);
    }
    //Updation Functions..........................
    void flip(int i,int x,int lx,int rx){
        if(rx-lx==1){
            sum[x] = 1 - sum[x];
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            flip(i,left(x),lx,m);
        }else{
            flip(i,right(x),m,rx);
        }
        sum[x] = sum[left(x)] + sum[right(x)];
    }
    void flip_index(int i){
        flip(i,0,0,size);
    }
    int find_k(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx;
        }
        int m = (lx+rx)/2;
        int ones_left = sum[left(x)];
        if(k<ones_left){
            return find_k(k,left(x),lx,m);
        }else{
            return find_k(k-ones_left,right(x),m,rx);
        }
    }
    int find(int k){
        return find_k(k,0,0,size);
    }
};
int main(){
    speed
    int n,q;
    cin>>n>>q;
    segment_tree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    st.build_segment_tree(a);
    while(q--){
        int op,i;
        cin>>op>>i;
        if(op==1){
            a[i] = 1 - a[i];
            st.flip_index(i);
        }else{
            //
            cout<<st.find(i)<<endl;
        }

    }
}

/*
1
8
-2 -3 4 -1 -2 1 5 -3
 */
