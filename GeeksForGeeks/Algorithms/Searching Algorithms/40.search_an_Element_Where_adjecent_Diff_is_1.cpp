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
int binarySearch(vector<int>& arr,int start,int end,int k,int n){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==k){
        return mid;
    }
    if(arr[mid]>k){
        int diff = arr[mid]-k;
        if(mid+diff<=n-1&&arr[mid+diff]==k){
            return mid+diff;
        }else if(mid-diff>=0&&arr[mid-diff]==k){
            return mid-diff;
        }else{
            int left = binarySearch(arr,start,mid-diff,k,n);
            int right = binarySearch(arr,mid+diff,end,k,n);
            return left!=-1?left:right;
        }
    }
    if(arr[mid]<k){
        int diff = k - arr[mid];
        if(mid+diff<=n-1&&arr[mid+diff]==k){
            return mid+diff;
        }else if(mid-diff>=0&&arr[mid-diff]==k){
            return mid-diff;
        }else{
            int left = binarySearch(arr,start,mid-diff,k,n);
            int right = binarySearch(arr,mid+diff,end,k,n);
            return left!=-1?left:right;
        }
    }
    return -1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int k;
    cin>>k;
    int index = binarySearch(arr,0,n-1,k,n);
    cout<<index<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}