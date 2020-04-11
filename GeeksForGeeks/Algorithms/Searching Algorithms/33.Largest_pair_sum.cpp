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
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int first = max(arr[0],arr[1]);
    int second = min(arr[0],arr[1]);
    fo(i,2,n-1){
        if(arr[i]>=first){
            second = first;
            first = arr[i];
        }else if(arr[i]>second){
            second = arr[i];
        }
    }
    cout<<(first+second)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
test_cases....
1
5
12 34 10 6 40
*/