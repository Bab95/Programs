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
int binarySearch(vector<int>& arr,int start,int end,int key){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return mid;
    }else if(arr[mid]>key){
        return binarySearch(arr,start,mid-1,key);
    }
    return binarySearch(arr,mid+1,end,key);
}
int findbound(vector<int>& arr,int key){
    int start = 0;
    int end = 1;
    int val = arr[0];
    while(val<key){
        start = end;
        end = end*2;
        val = arr[end];
    }
    return binarySearch(arr,start,end,key);
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int key;
    cin>>key;
    int ans = findbound(arr,key);
    cout<<arr[ans]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}