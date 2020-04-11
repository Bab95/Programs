#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <stack>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int binarySearch(vector<int>& arr,int start,int end){
    if(start==end){
        return arr[start];
    }
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(mid%2==0){
        //odd index....
        if(mid<end&&arr[mid]==arr[mid+1]){
            return binarySearch(arr,mid+2,end);
        }else{
            return binarySearch(arr,start,mid-2);
        }
    }else{
        if(mid>start&&arr[mid]==arr[mid-1]){
            return binarySearch(arr,mid+1,end);
        }else{
            return binarySearch(arr,start,mid-1);
        }
    }
    return -1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int element = binarySearch(arr,0,n-1);
    cout<<element<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}