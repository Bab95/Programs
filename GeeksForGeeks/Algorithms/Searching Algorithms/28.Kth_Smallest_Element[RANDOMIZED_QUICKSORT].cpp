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
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int findpivot(vector<int>& arr,int start,int end){
    int pivot = arr[end];
    //cout<<"pivot:"<<arr[end]<<endl;
    int i = start;
    for(int j = start;j<=end-1;++j){
        if(arr[j]<=pivot){
            swap(&arr[i],&arr[j]);
            ++i;
        }
    }
    swap(&arr[i],&arr[end]);
    return i;
}
int quicksort(vector<int>& arr,int start,int end,int k){
    //cout<<start<<" "<<end<<endl;
    if(start==end){
        return arr[start];
    }
    if(start<end){
        int random_index = (rand()%(end-start+1))+start;
        swap(&arr[random_index],&arr[end]);
        int pivot = findpivot(arr,start,end);
        //cout<<"pivot:"<<pivot<<endl;
        if(pivot==k){
            return arr[pivot];
        }else if(k<pivot){
            return quicksort(arr,start,pivot-1,k);
        }else{
            return quicksort(arr,pivot+1,end,k);
        }
    }
    return -1;
}
void solve(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    cin>>k;
    int ans = quicksort(arr,0,n-1,k-1);
    //if(ans!=-1){
        cout<<ans<<endl;
    //}
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}