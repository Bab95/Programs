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
void quicksort(vector<int>& arr,int start,int end){
    if(start<end){
        int random_index = (rand()%(end-start+1))+start;
        swap(&arr[random_index],&arr[end]);
        int pivot = findpivot(arr,start,end);
        /*if(pivot==k){
            return arr[pivot];
        }else if(pivot>k){
            return quicksort(arr,pivot+1,end,k);
        }else{
            return quicksort(arr,start,pivot-1,k);
        }*/
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
    //return -1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    quicksort(arr,0,n-1);
    fo(i,0,n-1){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
testcases....
2
6
7 10 4 3 20 15
19
7 2 10 36 16 89 562 1902 89 2131 455 123 980 453 2387 4765 29847 652 23211
*/
