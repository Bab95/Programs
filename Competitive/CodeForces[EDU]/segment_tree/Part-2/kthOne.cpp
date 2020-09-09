#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct segment_tree{
    vector<int> values;
    int size;
    void init(int n){
        size = 1;
        while(size<n){
            size *= 2;
        }
        values.assign(2*size,0);
    }
    int left(int x){
        return 2*x + 1;
    }
    int right(int x){
        return 2*x + 2;
    }
    void _build(vector<int>& arr,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)arr.size()){
                values[x] = arr[lx];
            }
            return;
        }
        int m = (lx+rx);
        _build(arr,left(x),lx,m);
        _build(arr,right(x),m,rx);
        values[x] = values[left(x)] + values[right(x)];
    }
    void build(vector<int>& arr){
        _build(arr,0,0,size);
    }
};
int main(){

}

/*
index of kth one....
a  1 0 1 1 0 1 0 0 0 1 0 1

*/