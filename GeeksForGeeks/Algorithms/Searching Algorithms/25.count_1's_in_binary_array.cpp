#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fi(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
using namespace std;
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
int binarySearch(vector<int>& arr,int start,int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==0){
        return binarySearch(arr,start,mid-1);
    }
    if(arr[mid]==1){
        if((mid<end&&arr[mid+1]==0)||(mid==end)){
            return mid;
        }else{
            return binarySearch(arr,mid+1,end);
        }
    }
    return -1;

}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int index = binarySearch(arr,0,n-1);
    cout<<index+1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
test cases....
3
8
1 1 0 0 0 0 0 0
7
1 1 1 1 1 1 1
7
0 0 0 0 0 0 0

*/