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
typedef long long int ll;
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
ll merge(vector<int>& arr,vector<int>& temp,int start,int mid,int end){
    int i,j,k;
    ll count = 0;
    i = start;
    j = mid;
    k = start;
    while(i<mid&&j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            count += (mid-i);
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(i=start;i<=end;++i){
        arr[i] = temp[i];
    }
    return count;
}
ll mergeSort(vector<int>& arr,vector<int>& temp,int start,int end){
    ll invs = 0;
    if(start<end){
        int mid = (start+end)/2;
        invs += mergeSort(arr,temp,start,mid);
        invs += mergeSort(arr,temp,mid+1,end);
        invs += merge(arr,temp,start,mid+1,end);
    }
    return invs;
}
ll countInversions(vector<int>& arr,int start,int end){
    ll invs = 0;
    vector<int> temp(arr.size());
    invs = mergeSort(arr,temp,start,end);
    return invs;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    ll inv = countInversions(arr,0,n-1);
    cout<<inv<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
