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
void selectionsort(vector<int>& arr,int n){
    for(int i=0;i<n-1;++i){
        int min_element = i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[i]){
                min_element = j;
            }
        }
        swap(&arr[i],&arr[min_element]);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    selectionsort(arr,n);
    print(arr,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}