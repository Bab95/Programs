#include <bits/stdc++.h>
using namespace std;
struct segment_Tree{
  int size;
  vector<int> values;

  int left(int x){
    return 2*x + 1;
  }

  int right(int x){
    return 2*x + 2;
  }

  void init(int n){
    size = 1;
    while(size<n){
      size *= 2;
    }
    values.assign(2*size,0);
  }
  //Build Segment tree
  void _build(vector<int>& a,int x,int lx,int rx){
    if(rx-lx==1){
      values[x] = a[lx];
      return;
    }
    int m = (lx+rx)/2;
    _build(a,left(x),lx,m);
    _build(a,right(x),m,rx);
    values[x] = values[left(x)] + values[right(x)];
  }
  void build(vector<int>& a){
    _build(a,0,0,size);
  }
  //function to set the value of a node.......
  void _set(int i,int v,int x,int lx,int rx){
    if(rx-lx==1){
      values[x] = v;
      return;
    }
    int m = (lx+rx)/2;
    if(i<m){
      _set(i,v,left(x),lx,m);
    }else{
      _set(i,v,right(x),m,rx);
    }
  }

  void set(int i,int v){
    _set(i,v,0,0,size);
  }
  long int get_sum(int l,int r,int x,int lx,int rx){
    if(lx>=r || rx<=l){
      return 0;
    }
    if(lx>=l&&rx<=r){
      return values[x];
    }
    int m = (lx+rx)/2;
    int left_sum = get_sum(l,r,left(x),lx,m);
    int right_sum = get_sum(l,r,right(x),m,rx);
    return left_sum + right_sum;
  }
  long int query(int l,int r){
    return get_sum(l,r,0,0,size);
  }
};
int main(){
  int n,m;
  vector<int> arr(n);
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }

}
